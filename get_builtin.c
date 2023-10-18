#include "main.h"

/**
 * find_builtin - locates and returns a pointer to a builtin function
 *
 * @command: command
 * Return: function pointer to the corresponding builtin command
 */
int (*find_builtin(char *command))(custom_data *)
{
        custom_builtin_t builtins[] = {
                { "env", custom_env },
                { "exit", custom_exit },
                { "setenv", custom_setenv },
                { "unsetenv", custom_unsetenv },
                { "cd", custom_cd },
                { "help", custom_help },
                { NULL, NULL }
        };
        int index = 0;

        while (builtins[index].name != NULL)
        {
                if (_strcmp(builtins[index].name, command) == 0)
                {
                        break;
                }
                index++;
        }

        return (builtins[index].func);
}
