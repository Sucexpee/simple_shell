#include "main.h"

/**
 * concatenate_cd_error - Concatenates an error message for the "cd" command.
 *
 * @custom_data: Custom data structure containing relevant data (directory)
 * @message: Message to print
 * @error_message: Output message
 * @counter_str: Counter lines
 * Return: Error message
 */
char *concatenate_cd_error(custom_data *custom_data, char *message, char *error_message, char *counter_str)
{
        char *illegal_flag;

        custom_strcpy(error_message, custom_data->program_name);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, counter_str);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, custom_data->arguments[0]);
        custom_strcat(error_message, message);

        if (custom_data->arguments[1][0] == '-')
        {
                illegal_flag = custom_malloc(3);
                illegal_flag[0] = '-';
                illegal_flag[1] = custom_data->arguments[1][1];
                illegal_flag[2] = '\0';
                custom_strcat(error_message, illegal_flag);
                custom_free(illegal_flag);
        }
        else
        {
                custom_strcat(error_message, custom_data->arguments[1]);
        }

        custom_strcat(error_message, "\n");
        custom_strcat(error_message, "\0");
        return (error_message);
}

/**
 * generate_cd_error - Generates an error message for the "cd" command.
 * @custom_data: Custom data structure containing relevant data (directory)
 * Return: Error message
 */
char *generate_cd_error(custom_data *custom_data)
{
        int length, identifier_length;
        char *error_message, *counter_str, *message;

        counter_str = custom_itoa(custom_data->counter);

        if (custom_data->arguments[1][0] == '-')
        {
                message = ": Illegal option ";
                identifier_length = 2;
        }
        else
        {
                message = ": can't cd to ";
                identifier_length = custom_strlen(custom_data->arguments[1]);
        }

        length = custom_strlen(custom_data->program_name) + custom_strlen(custom_data->arguments[0]);
        length += custom_strlen(counter_str) + custom_strlen(message) + identifier_length + 5;

        error_message = custom_malloc(sizeof(char) * (length + 1));

        if (error_message == 0)
        {
                custom_free(counter_str);
                return (NULL);
        }

        error_message = concatenate_cd_error(custom_data, message, error_message, counter_str);

        custom_free(counter_str);

        return (error_message);
}

/**
 * generate_command_not_found_error - Generates a "command not found" error message.
 * @custom_data: Custom data structure containing relevant data (counter, arguments)
 * Return: Error message
 */
char *generate_command_not_found_error(custom_data *custom_data)
{
        int length;
        char *error_message;
        char *counter_str;

        counter_str = custom_itoa(custom_data->counter);

        length = custom_strlen(custom_data->program_name) + custom_strlen(counter_str);
        length += custom_strlen(custom_data->arguments[0]) + 16;

        error_message = custom_malloc(sizeof(char) * (length + 1));

        if (error_message == 0)
        {
                custom_free(error_message);
                custom_free(counter_str);
                return (NULL);
        }

        custom_strcpy(error_message, custom_data->program_name);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, counter_str);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, custom_data->arguments[0]);
        custom_strcat(error_message, ": not found\n");
        custom_strcat(error_message, "\0");
        custom_free(counter_str);

        return (error_message);
}

/**
 * generate_exit_shell_error - Generates an error message for the "exit" command.
 * @custom_data: Custom data structure containing relevant data (counter, arguments)
 * Return: Error message
 */
char *generate_exit_shell_error(custom_data *custom_data)
{
        int length;
        char *error_message;
        char *counter_str;

        counter_str = custom_itoa(custom_data->counter);

        length = custom_strlen(custom_data->program_name) + custom_strlen(counter_str);
        length += custom_strlen(custom_data->arguments[0]) + custom_strlen(custom_data->arguments[1]) + 23;

        error_message = custom_malloc(sizeof(char) * (length + 1));

        if (error_message == 0)
        {
                custom_free(counter_str);
                return (NULL);
        }

        custom_strcpy(error_message, custom_data->program_name);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, counter_str);
        custom_strcat(error_message, ": ");
        custom_strcat(error_message, custom_data->arguments[0]);
        custom_strcat(error_message, ": Illegal number: ");
        custom_strcat(error_message, custom_data->arguments[1]);
        custom_strcat(error_message, "\n\0");
        custom_free(counter_str);

        return (error_message);
}
