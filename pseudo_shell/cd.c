#include "main.h"

/**
 * custom_cd_dot - Navigate to the parent directory
 *
 * @datash: Relevant data (environment)
 *
 * Return: No return
 */
void custom_cd_dot(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPATH", cp_pwd, datash);
	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("CURPATH", cp_pwd, datash);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("CURPATH", cp_strtok_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env("CURPATH", "/", datash);
	}
	datash->status = 0;
	free(cp_pwd);
}

/**
 * custom_cd_to - Navigate to the specified directory
 * given by the user
 *
 * @datash: Relevant data (directories)
 * Return: No return
 */
void custom_cd_to(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		get_error(datash, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("OLDPATH", cp_pwd, datash);

	cp_dir = _strdup(dir);
	set_env("CURPATH", cp_dir, datash);

	free(cp_pwd);
	free(cp_dir);

	datash->status = 0;

	chdir(dir);
}

/**
 * custom_cd_previous - Navigate to the previous directory
 *
 * @datash: Relevant data (environment)
 * Return: No return
 */
void custom_cd_previous(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpath, *cp_pwd, *cp_oldpath;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpath = _getenv("OLDPATH", datash->_environ);

	if (p_oldpath == NULL)
		cp_oldpath = cp_pwd;
	else
		cp_oldpath = _strdup(p_oldpath);

	set_env("OLDPATH", cp_pwd, datash);

	if (chdir(cp_oldpath) == -1)
		set_env("CURPATH", cp_pwd, datash);
	else
		set_env("CURPATH", cp_oldpath, datash);

	p_pwd = _getenv("CURPATH", datash->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpath)
		free(cp_oldpath);

	datash->status = 0;

	chdir(p_pwd);
}

/**
 * custom_cd_to_home - Navigate to the home directory
 *
 * @datash: Relevant data (environment)
 * Return: No return
 */
void custom_cd_to_home(data_shell *datash)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", datash->_environ);

	if (home == NULL)
	{
		set_env("OLDPATH", p_pwd, datash);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(datash, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPATH", p_pwd, datash);
	set_env("CURPATH", home, datash);
	free(p_pwd);
	datash->status = 0;
}

