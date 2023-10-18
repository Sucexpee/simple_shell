#include "main.h"

/**
 * handle_sigint - Handle the Ctrl+C signal in the prompt
 * @signal: Signal handler
 */
void handle_sigint(int signal)
{
(void)signal;
write(STDOUT_FILENO, "\nCtrl+C was pressed! :)", 22);
}
