#include "main.h"

/**
 * count_repeats - calculates the consecutive character repetitions.
 *
 * @input: input string
 * @i: index
 * Return: number of consecutive repetitions.
 */
int count_repeats(char *input, int i)
{
	if (*(input - 1) == *input)
		return (count_repeats(input - 1, i + 1));

	return (i);
}

/**
 * find_syntax_error - locates syntax errors in the input.
 *
 * @input: input string
 * @i: index
 * @last: last character processed
 * Return: index of the error, 0 if no errors found.
 */
int find_syntax_error(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (find_syntax_error(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = count_repeats(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = count_repeats(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (find_syntax_error(input + 1, i + 1, *input));
}

/**
 * find_first_char - identifies the index of the first non-whitespace character.
 *
 * @input: input string
 * @i: index
 * Return: 1 if an error is found, 0 otherwise.
 */
int find_first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * report_syntax_error - displays a syntax error message.
 *
 * @datash: data structure
 * @input: input string
 * @i: index of the error
 * @bool: message control
 * Return: no return
 */
void report_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * validate_syntax - checks for syntax errors in the input.
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if an error is found, 0 otherwise.
 */
int validate_syntax(data_shell *datash, char *input)
{
	int start = 0;
	int first_char_found = 0;
	int i = 0;

	first_char_found = find_first_char(input, &start);
	if (first_char_found == -1)
	{
		report_syntax_error(datash, input, start, 0);
		return (1);
	}

	i = find_syntax_error(input + start, 0, *(input + start));
	if (i != 0)
	{
		report_syntax_error(datash, input, start + i, 1);
		return (1);
	}

	return (0);
}

