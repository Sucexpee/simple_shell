#include "custom_header.h"

/**
 * lookup_environment - scan the environment for variable matches
 *
 * @list_head: head of linked list
 * @input_str: input string
 * @custom_data: custom data structure
 * Return: no return
 */
void lookup_environment(env_variable **list_head, char *input_str, custom_data *custom_data)
{
	int row_index, char_index, var_length;
	char **env_vars;

	env_vars = custom_data->environment;

	for (row_index = 0; env_vars[row_index]; row_index++)
	{
		for (var_length = 1, char_index = 0; env_vars[row_index][char_index]; char_index++)
		{
			if (env_vars[row_index][char_index] == '=')
			{
				var_length = custom_strlen(env_vars[row_index] + char_index + 1);
				add_environment_var(list_head, var_length, env_vars[row_index] + char_index + 1);
				return;
			}

			if (input_str[var_length] == env_vars[row_index][char_index])
				var_length++;
			else
				break;
		}
	}

	for (var_length = 0; input_str[var_length]; var_length++)
	{
		if (input_str[var_length] == ' ' || input_str[var_length] == '\t' || input_str[var_length] == ';' || input_str[var_length] == '\n')
			break;
	}

	add_environment_var(list_head, var_length, NULL);
}

/**
 * process_variables - process and identify special variables
 *
 * @list_head: head of the linked list
 * @input_str: input string
 * @last_status: last status of the Shell
 * @custom_data: custom data structure
 * Return: length of processed variables
 */
int process_variables(env_variable **list_head, char *input_str, char *last_status, custom_data *custom_data)
{
	int i, last_status_length, pid_length;

	last_status_length = custom_strlen(last_status);
	pid_length = custom_strlen(custom_data->process_id);

	for (i = 0; input_str[i]; i++)
	{
		if (input_str[i] == '$')
		{
			if (input_str[i + 1] == '?')
				add_environment_var(list_head, 2, last_status), i++;
			else if (input_str[i + 1] == '$')
				add_environment_var(list_head, 2, custom_data->process_id), i++;
			else if (input_str[i + 1] == '\n')
				add_environment_var(list_head, 0, NULL);
			else if (input_str[i + 1] == '\0')
				add_environment_var(list_head, 0, NULL);
			else if (input_str[i + 1] == ' ')
				add_environment_var(list_head, 0, NULL);
			else if (input_str[i + 1] == '\t')
				add_environment_var(list_head, 0, NULL);
			else if (input_str[i + 1] == ';')
				add_environment_var(list_head, 0, NULL);
			else
				lookup_environment(list_head, input_str + i, custom_data);
		}
	}

	return (i);
}

/**
 * replace_input_variables - replace string with identified variables
 *
 * @list_head: head of the linked list
 * @input_str: input string
 * @new_input: new input string (replaced)
 * @new_length: new length
 * Return: replaced string
 */
char *replace_input_variables(env_variable **list_head, char *input_str, char *new_input, int new_length)
{
	env_variable *current_var;
	int i, j, k;

	current_var = *list_head;
	for (j = i = 0; i < new_length; i++)
	{
		if (input_str[j] == '$')
		{
			if (!(current_var->var_length) && !(current_var->val_length))
			{
				new_input[i] = input_str[j];
				j++;
			}
			else if (current_var->var_length && !(current_var->val_length))
			{
				for (k = 0; k < current_var->var_length; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < current_var->val_length; k++)
				{
					new_input[i] = current_var->value[k];
					i++;
				}
				j += (current_var->var_length);
				i--;
			}
			current_var = current_var->next;
		}
		else
		{
			new_input[i] = input_str[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * replace_custom_variables - replace custom variables in the input string
 *
 * @input_str: input string
 * @custom_data: custom data structure
 * Return: replaced string
 */
char *replace_custom_variables(char *input_str, custom_data *custom_data)
{
	env_variable *list_head, *current_var;
	char *last_status, *new_input;
	int input_length, new_length;

	last_status = custom_itoa(custom_data->status);
	list_head = NULL;

	input_length = process_variables(&list_head, input_str, last_status, custom_data);

	if (list_head == NULL)
	{
		custom_free(last_status);
		return (input_str);
	}

	current_var = list_head;
	new_length = 0;

	while (current_var != NULL)
	{
		new_length += (current_var->val_length - current_var->var_length);
		current_var = current_var->next;
	}

	new_length += input_length;

	new_input = custom_malloc(sizeof(char) * (new_length + 1));
	new_input[new_length] = '\0';

	new_input = replace_input_variables(&list_head, input_str, new_input, new_length);

	custom_free(input_str);
	custom_free(last_status);
	custom_free_environment_list(&list_head);

	return (new_input);
}
