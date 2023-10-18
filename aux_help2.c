#include "main.h"

/**
 * display_help - Display help information for the built-in "help" command.
 * Return: No return.
 */
void display_help(void)
{
        char *help_message = "help: help [-dms] [pattern ...]\n";

        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "\tDisplay information about built-in commands.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "Displays brief summaries of built-in commands.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
root@a849e071647f:~/simple_shell/pseudo_shell# ls
aux_error1.c  aux_lists2.c  aux_str2.c  cd_shell.c            env2.c         get_error.c   main.c
aux_error2.c  aux_lists.c   aux_str3.c  check_syntax_error.c  exec_line.c    get_help.c    main.h
aux_help2.c   aux_mem.c     aux_str.c   cmd_exec.c            exit_shell.c   get_line.c    read_line.c
aux_help.c    aux_stdlib.c  cd.c        env1.c                get_builtin.c  get_sigint.c  rep_var.c
root@a849e071647f:~/simple_shell/pseudo_shell# cat aux_help2.c  
#include "main.h"

/**
 * display_help - Display help information for the built-in "help" command.
 * Return: No return.
 */
void display_help(void)
{
        char *help_message = "help: help [-dms] [pattern ...]\n";

        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "\tDisplay information about built-in commands.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "Displays brief summaries of built-in commands.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
}

/**
 * display_alias_help - Display help information for the built-in "alias" command.
 * Return: No return.
 */
void display_alias_help(void)
{
        char *help_message = "alias: alias [-p] [name[=value]...]\n";

        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "\tDefine or display aliases.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
}

/**
 * display_cd_help - Display help information for the built-in "cd" command.
 * Return: No return.
 */
void display_cd_help(void)
{
        char *help_message = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
        help_message = "\tChange the shell working directory.\n";
        write(STDOUT_FILENO, help_message, custom_strlen(help_message));
}
