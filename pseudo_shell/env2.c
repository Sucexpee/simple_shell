#include "main.h"

/**
 * copy_env_entry - Create a copy of an environment variable entry.
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 *
 * Return: New environment variable string.
 */
char *copy_env_entry(char *name, char *value)
{
	int len_name = _strlen(name);
	int len_value = _strlen(value);
	int len = len_name + len_value + 2;
	char *entry = malloc(sizeof(char) * len);

	if (!entry)
		return (NULL);

	_strcpy(_strcpy(_strcpy(entry, name), "="), value);
	return (entry);
}

/**
 * set_env - Set an environment variable.
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 * @datash: Shell data structure.
 *
 * Return: No return value.
 */
void set_env(char *name, char *value, data_shell *datash)
{
	if (!name || !value || !datash)
		return;

	int i = 0;
	char *var_env, *name_env;

	while (datash->_environ[i])
	{
		var_env = _strdup(datash->_environ[i]);
		if (!var_env)
			return;

		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_env_entry(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
		i++;
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_env_entry(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - Compare environment variable names with the name provided.
 * @datash: Data relevant to environment variable name and value.
 *
 * Return: 1 on success, 0 on failure.
 */
int _setenv(data_shell *datash)
{
	if (!datash || !datash->args[1] || !datash->args[2])
	{
		get_error(datash, -1);
		return (0);
	}

	set_env(datash->args[1], datash->args[2], datash);
	return (1);
}

/**
 * _unsetenv - Remove an environment variable.
 * @datash: Data relevant to environment variable name.
 *
 * Return: 1 on success, 0 on failure.
 */
int _unsetenv(data_shell *datash)
{
	if (!datash || !datash->args[1])
	{
		get_error(datash, -1);
		return (0);
	}

	int i = 0, j = 0, k = -1;
	char **realloc_environ;
	char *var_env, *name_env;

	while (datash->_environ[i])
	{
		var_env = _strdup(datash->_environ[i]);
		if (!var_env)
			return (0);

		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
		i++;
	}

	if (k == -1)
	{
		get_error(datash, -1);
		return (0);
	}

	realloc_environ = malloc(sizeof(char *) * (i));
	if (!realloc_environ)
		return (0);

	for (i = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}

	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
