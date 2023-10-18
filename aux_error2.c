#include "main.h"

/**
 * generate_env_error - Generate an environment-related error message.
 *
 * @custom_data: Custom data structure containing relevant data (counter, arguments)
 * Return: Error message.
 */
char *generate_env_error(custom_data *custom_data)
{
        int length;
        char *error_msg;
        char *counter_str;
        char *message;

        counter_str = custom_itoa(custom_data->counter);
        message = ": Unable to modify environment\n";
        length = custom_strlen(custom_data->program_name) + custom_strlen(counter_str);
        length += custom_strlen(custom_data->arguments[0]) + custom_strlen(message) + 4;
        error_msg = custom_malloc(sizeof(char) * (length + 1));

        if (error_msg == 0)
        {
                custom_free(error_msg);
                custom_free(counter_str);
                return (NULL);
        }

        custom_strcpy(error_msg, custom_data->program_name);
        custom_strcat(error_msg, ": ");
        custom_strcat(error_msg, counter_str);
        custom_strcat(error_msg, ": ");
        custom_strcat(error_msg, custom_data->arguments[0]);
        custom_strcat(error_msg, message);
        custom_strcat(error_msg, "\0");
        custom_free(counter_str);

        return (error_msg);
}

/**
 * generate_permission_error - Generate a permission denied error message.
 *
 * @custom_data: Custom data structure containing relevant data (counter, arguments)
 * Return: Error message.
 */
char *generate_permission_error(custom_data *custom_data)
{
        int length;
        char *counter_str;
        char *error_msg;

        counter_str = custom_itoa(custom_data->counter);
        length = custom_strlen(custom_data->program_name) + custom_strlen(counter_str);
        length += custom_strlen(custom_data->arguments[0]) + 24;
        error_msg = custom_malloc(sizeof(char) * (length + 1));

        if (error_msg == 0)
        {
                custom_free(error_msg);
                custom_free(counter_str);
                return (NULL);
        }

        custom_strcpy(error_msg, custom_data->program_name);
        custom_strcat(error_msg, ": ");
        custom_strcat(error_msg, counter_str);
        custom_strcat(error_msg, ": ");
        custom_strcat(error_msg, custom_data->arguments[0]);
        custom_strcat(error_msg, ": Permission denied\n");
        custom_strcat(error_msg, "\0");
        custom_free(counter_str);

        return (error_msg);
}
