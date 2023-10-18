#include "custom.h"

/**
 * prepare_input - assigns input from source to buffer
 * @destination: Buffer that stores the input string
 * @size: Size of the buffer
 * @source: Source to read from
 * Return: The number of bytes read
 */
ssize_t prepare_input(char **destination, size_t *size, FILE *source)
{
	int i;
	static ssize_t bytesRead;
	ssize_t result;
	char *buffer;
	char character = 'z';

	if (bytesRead == 0)
		fflush(source);
	else
		return (-1);
	bytesRead = 0;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);

	while (character != '\n')
	{
		i = read(STDIN_FILENO, &character, 1);
		if (i == -1 || (i == 0 && bytesRead == 0))
		{
			free(buffer);
			return (-1);
		}

		if (i == 0 && bytesRead != 0)
		{
			bytesRead++;
			break;
		}

		if (bytesRead >= BUFFER_SIZE)
			buffer = _realloc(buffer, bytesRead, bytesRead + 1);

		buffer[bytesRead] = character;
		bytesRead++;
	}

	buffer[bytesRead] = '\0';
	assign_input(destination, size, buffer, bytesRead);
	result = bytesRead;

	if (i != 0)
		bytesRead = 0;

	return (result);
}

/**
 * assign_input - Assigns the line variable for get_input
 * @lineptr: Buffer that stores the input string
 * @n: Size of lineptr
 * @buffer: String that is copied to lineptr
 * @length: Size of buffer
 */
void assign_input(char **lineptr, size_t *n, char *buffer, size_t length)
{
	if (*lineptr == NULL)
	{
		if (length > BUFFER_SIZE)
			*n = length;
		else
			*n = BUFFER_SIZE;
		*lineptr = buffer;
	}
	else if (*n < length)
	{
		if (length > BUFFER_SIZE)
			*n = length;
		else
			*n = BUFFER_SIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

