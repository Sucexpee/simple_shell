#include "main.h"

/**
 * change_directory - Change the current directory.
 *
 * @datash: Data relevant.
 * Return: 1 on success.
 */
int change_directory(data_shell *datash)
{
	char *new_dir;
	int is_home, is_home2, is_ddash;

	new_dir = datash->args[1];

	if (new_dir != NULL)
	{
		is_home = _strcmp("$HOME", new_dir);
		is_home2 = _strcmp("~", new_dir);
		is_ddash = _strcmp("--", new_dir);
	}

	if (new_dir == NULL || !is_home || !is_home2 || !is_ddash)
	{
		navigate_home(datash);
		return (1);
	}

	if (_strcmp("-", new_dir) == 0)
	{
		go_back(datash);
		return (1);
	}

	if (_strcmp(".", new_dir) == 0 || _strcmp("..", new_dir) == 0)
	{
		navigate_relative(datash);
		return (1);
	}

	change_to_dir(datash);

	return (1);
}

