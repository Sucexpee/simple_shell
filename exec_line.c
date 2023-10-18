#include "main.h"

/**
 * run_command - checks for builtins and executes commands
 *
 * @data: custom data structure
 * Return: 1 on success.
 */
int run_command(custom_data *data)
{
        int (*internal)(custom_data *data);

        if (data->command[0] == NULL)
                return (1);

        internal = find_builtin(data->command[0]);

        if (internal != NULL)
                return (internal(data));

        return (execute_command(data));
}
