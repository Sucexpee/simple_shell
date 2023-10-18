#include "custom.h"
#include "main.h"
#include "custom_header.h"
/**
 * cleanupData - Frees data structure.
 *
 * @data: Data structure
 */
void cleanupData(data_shell *data)
{
    unsigned int i;

    for (i = 0; data->environment[i]; i++)
    {
        free(data->environment[i]);
    }

    free(data->environment);
    free(data->process_id);
}

/**
 * initializeData - Initializes data structure.
 *
 * @data: Data structure
 * @args: Argument vector
 */
void initializeData(data_shell *data, char **args)
{
    unsigned int i;

    data->arguments = args;
    data->input = NULL;
    data->parsedArguments = NULL;
    data->status = 0;
    data->commandCounter = 1;
    for (i = 0; environ[i]; i++)
    {
        data->environment[i] = strdup(environ[i]);
    }

    data->environment[i] = NULL;
    data->process_id = intToString(getpid());
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
    data_shell data;
    (void)argc;

    signal(SIGINT, handle_sigint);
    initializeData(&data, argv);
    shellLoop(&data);
    cleanupData(&data);

    if (data.status < 0)
    {
        return (255);
    }
    return (data.status);
}
