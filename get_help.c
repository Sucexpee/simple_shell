#include "main.h"

/**
 * provide_guidance - offers help messages for builtins
 * @datash: data structure (arguments and input)
 * Return: Always returns 0
*/
int provide_guidance(custom_data *datash)
{
        if (datash->args[1] == 0)
                show_general_help();
        else if (custom_strcmp(datash->args[1], "setenv") == 0)
                show_setenv_help();
        else if (custom_strcmp(datash->args[1], "env") == 0)
                show_env_help();
        else if (custom_strcmp(datash->args[1], "unsetenv") == 0)
                show_unsetenv_help();
        else if (custom_strcmp(datash->args[1], "help") == 0)
                show_general_help();
        else if (custom_strcmp(datash->args[1], "exit") == 0)
                show_exit_help();
        else if (custom_strcmp(datash->args[1], "cd") == 0)
                show_cd_help();
        else if (custom_strcmp(datash->args[1], "alias") == 0)
                show_alias_help();
        else
                write(STDERR_FILENO, datash->args[0], custom_strlen(datash->args[0]));

        datash->status = 0;
        return (1);
}
