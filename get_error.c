#include "main.h"

/**
 * report_error - handles errors based on the error code
 *
 * @datash: data structure containing arguments
 * @err_code: error code
 * Return: returns the error code
 */
int report_error(custom_data *datash, int err_code)
{
        char *error_msg;

        switch (err_code)
        {
        case -1:
                error_msg = custom_error_env(datash);
                break;
        case 126:
                error_msg = custom_error_path_126(datash);
                break;
        case 127:
                error_msg = custom_error_not_found(datash);
                break;
        case 2:
                if (custom_strcmp("exit", datash->args[0]) == 0)
                        error_msg = custom_error_exit_shell(datash);
                else if (custom_strcmp("cd", datash->args[0]) == 0)
                        error_msg = custom_error_cd(datash);
                break;
        }

        if (error_msg)
        {
                write(STDERR_FILENO, error_msg, custom_strlen(error_msg));
                free(error_msg);
        }

        datash->status = err_code;
        return (err_code);
}
