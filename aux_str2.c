#include "main.h"

/**
 * my_strdup - Duplicate a string in the heap memory.
 * @s: The source string.
 * Return: A duplicated string.
 */
char *my_strdup(const char *s)
{
        char *new;
        size_t len;

        len = my_strlen(s);
        new = malloc(sizeof(char) * (len + 1));
        if (new == NULL)
                return (NULL);
        my_memcpy(new, s, len + 1);
        return (new);
}

/**
 * my_strlen - Get the length of a string.
 * @s: The string to measure.
 * Return: The length of the string.
 */
int my_strlen(const char *s)
{
        int len;

        for (len = 0; s[len] != 0; len++)
        {
        }
        return (len);
}

/**
 * compare_chars - Compare characters in strings.
 * @str: The input string.
 * @delim: The delimiter string.
 * Return: 1 if the characters are equal, 0 if not.
 */
int compare_chars(char str[], const char *delim)
{
        unsigned int i, j, k;

        for (i = 0, k = 0; str[i]; i++)
        {
                for (j = 0; delim[j]; j++)
                {
                        if (str[i] == delim[j])
                        {
                                k++;
                                break;
                        }
                }
        }
        if (i == k)
                return (1);
        return (0);
}

/**
 * my_strtok - Split a string by a delimiter.
 * @str: The input string.
 * @delim: The delimiter.
 * Return: The split string.
 */
char *my_strtok(char str[], const char *delim)
{
        static char *splitted, *str_end;
        char *str_start;
        unsigned int i, bool;

        if (str != NULL)
        {
                if (compare_chars(str, delim))
                        return (NULL);
                splitted = str; /* Store the first address */
                i = my_strlen(str);
                str_end = &str[i]; /* Store the last address */
        }
        str_start = splitted;
        if (str_start == str_end) /* Reached the end */
                return (NULL);

        for (bool = 0; *splitted; splitted++)
        {
                /* Break the loop finding the next token */
                if (splitted != str_start)
                        if (*splitted && *(splitted - 1) == '\0')
                                break;
                /* Replace delimiter with a null character */
                for (i = 0; delim[i]; i++)
                {
                        if (*splitted == delim[i])
                        {
                                *splitted = '\0';
                                if (splitted == str_start)
                                        str_start++;
                                break;
                        }
                }
                if (bool == 0 && *splitted) /* Str != Delim */
                        bool = 1;
        }
        if (bool == 0) /* Str == Delim */
                return (NULL);
        return (str_start);
}

/**
 * my_isdigit - Check if a string is a number.
 * @s: The input string.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int my_isdigit(const char *s)
{
        unsigned int i;

        for (i = 0; s[i]; i++)
        {
                if (s[i] < 48 || s[i] > 57)
                        return (0);
        }
        return (1);
}
