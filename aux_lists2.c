#include "main.h"

/**
 * add_rvar_node - Add a variable at the end of an r_var list.
 *
 * @head: Head of the linked list.
 * @var_length: Length of the variable.
 * @value: Value of the variable.
 * @value_length: Length of the value.
 * Return: Address of the head.
 */
r_var *add_rvar_node(r_var **head, int var_length, char *value, int value_length)
{
        r_var *new_node, *temp;

        new_node = custom_malloc(sizeof(r_var));

        if (new_node == NULL)
                return (NULL);

        new_node->len_var = var_length;
        new_node->val = value;
        new_node->len_val = value_length;

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
 * free_rvar_list - Free an r_var list.
 *
 * @head: Head of the linked list.
 * Return: No return.
 */
void free_rvar_list(r_var **head)
{
        r_var *temp;
        r_var *current;

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
