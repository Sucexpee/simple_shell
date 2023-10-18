#include "main.h"

/**
 * my_get_length - Calculate the length of an integer.
 * @num: An integer.
 * Return: The length of the integer.
 */
int my_get_length(int num)
{
        unsigned int num_copy;
        int length = 1;

        if (num < 0)
        {
                length++;
                num_copy = num * -1;
        }
        else
        {
                num_copy = num;
        }

        while (num_copy > 9)
        {
                length++;
                num_copy = num_copy / 10;
        }

        return (length);
}

/**
 * my_itoa - Convert an integer to a string.
 * @num: An integer.
 * Return: The integer as a string.
 */
char *my_itoa(int num)
{
        unsigned int num_copy;
        int length = my_get_length(num);
        char *result;

        result = malloc(sizeof(char) * (length + 1));
        if (result == 0)
                return (NULL);

        *(result + length) = '\0';

        if (num < 0)
        {
                num_copy = num * -1;
                result[0] = '-';
        }
        else
        {
                num_copy = num;
        }

        length--;
        do {
                *(result + length) = (num_copy % 10) + '0';
                num_copy = num_copy / 10;
                length--;
        } while (num_copy > 0);

        return (result);
}

/**
 * my_atoi - Convert a string to an integer.
 * @str: The input string.
 * Return: An integer.
 */
int my_atoi(char *str)
{
        unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

        while (*(str + count) != '\0')
        {
                if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
                        break;

                if (*(str + count) == '-')
                        sign *= -1;

                if ((*(str + count) >= '0') && (*(str + count) <= '9'))
                {
                        if (size > 0)
                                multiplier *= 10;
                        size++;
                }
                count++;
        }

        for (i = count - size; i < count; i++)
        {
                result = result + ((*(str + i) - 48) * multiplier);
                multiplier /= 10;
        }
        return (result * sign);
}
