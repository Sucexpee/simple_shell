#include "main.h"

/**
 * my_strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: The destination string.
 */
char *my_strcat(char *dest, const char *src)
{
        int i, j;

        for (i = 0; dest[i] != '\0'; i++)
                ;

        for (j = 0; src[j] != '\0'; j++)
        {
                dest[i] = src[j];
                i++;
        }

        dest[i] = '\0';
        return (dest);
}

/**
 * my_strcpy - Copy a string.
 * @dest: The destination string.
 * @src: The source string.
 * Return: The destination string.
 */
char *my_strcpy(char *dest, char *src)
{
        size_t a;

        for (a = 0; src[a] != '\0'; a++)
        {
                dest[a] = src[a];
        }
        dest[a] = '\0';

        return (dest);
}

/**
 * my_strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if equal, positive if s1 > s2, negative if s1 < s2.
 */
int my_strcmp(char *s1, char *s2)
{
        int i;

        for (i = 0; s1[i] == s2[i] && s1[i]; i++)
                ;

        if (s1[i] > s2[i])
                return (1);
        if (s1[i] < s2[i])
                return (-1);
        return (0);
}

/**
 * my_strchr - Locate a character in a string.
 * @s: The string to search.
 * @c: The character to find.
 * Return: A pointer to the first occurrence of the character c, or NULL.
 */
char *my_strchr(char *s, char c)
{
        unsigned int i = 0;

        for (; *(s + i) != '\0'; i++)
                if (*(s + i) == c)
                        return (s + i);
        if (*(s + i) == c)
                return (s + i);
        return (NULL);
}

/**
 * my_strspn - Get the length of a prefix substring.
 * @s: The initial segment.
 * @accept: The accepted bytes.
 * Return: The number of accepted bytes.
 */
int my_strspn(char *s, char *accept)
{
        int i, j, bool;

        for (i = 0; *(s + i) != '\0'; i++)
        {
                bool = 1;
                for (j = 0; *(accept + j) != '\0'; j++)
                {
                        if (*(s + i) == *(accept + j)
                        {
                                bool = 0;
                                break;
                        }
                }
                if (bool == 1)
                        break;
        }
        return (i);
}
