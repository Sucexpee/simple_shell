#include "main.h"

/**
 * add_separator_node_end - Adds a separator found at the end of a sep_list.
 *
 * @head: Head of the linked list.
 * @separator: Separator found (; | &).
 * Return: Address of the head.
 */
sep_list *add_separator_node_end(sep_list **head, char separator)
{
        sep_list *new_node, *temp;

        new_node = custom_malloc(sizeof(sep_list));

        if (new_node == NULL)
                return (NULL);

        new_node->separator = separator;
        new_node->next = NULL;
        temp = *head;

        if (temp == NULL)
        {
                *head = new_node;
        }
        else
        {
                while (temp->next != NULL)
                        temp = temp->next;
                temp->next = new_node;
        }

        return (*head);
}

/**
 * free_separator_list - Frees a sep_list.
 *
 * @head: Head of the linked list.
 * Return: No return.
 */
void free_separator_list(sep_list **head)
{
        sep_list *temp;
        sep_list *current;

        if (head != NULL)
        {
                current = *head;
                while ((temp = current) != NULL)
                {
                        current = current->next;
                        custom_free(temp);
                }
                *head = NULL;
        }
}

/**
 * add_command_line_node_end - Adds a command line at the end of a line_list.
 *
 * @head: Head of the linked list.
 * @line: Command line.
 * Return: Address of the head.
 */
line_list *add_command_line_node_end(line_list **head, char *line)
{
        line_list *new_node, *temp;

        new_node = custom_malloc(sizeof(line_list));

        if (new_node == NULL)
                return (NULL);

        new_node->line = line;
        new_node->next = NULL;
        temp = *head;

        if (temp == NULL)
        {
                *head = new_node;
        }
        else
        {
                while (temp->next != NULL)
                        temp = temp->next;
                temp->next = new_node;
        }

        return (*head);
}

/**
 * free_command_line_list - Frees a line_list.
 *
 * @head: Head of the linked list.
 * Return: No return.
 */
void free_command_line_list(line_list **head)
{
        line_list *temp;
        line_list *current;

        if (head != NULL)
        {
                current = *head;
                while ((temp = current) != NULL)
                {
                        current = current->next;
                        custom_free(temp);
                }
                *head = NULL;
        }
}
