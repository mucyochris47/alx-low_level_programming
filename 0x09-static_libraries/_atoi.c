#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
    int num = 0;
    int sign = 1;
    int started = 0;

    while (*s)
    {
        if (*s == '-')
            sign *= -1;
        else if (*s >= '0' && *s <= '9')
        {
            num = num * 10 + (*s - '0');
            started = 1;
        }
        else if (started)
            break;
        s++;
    }

    return (num * sign);
}
