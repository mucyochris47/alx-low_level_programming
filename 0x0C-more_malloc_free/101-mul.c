#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Include the string.h header for strlen */

/**
 * is_digit - checks if a string contains only digits
 * @str: the string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    int i, j, len1, len2, len_res;
    int *res;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        return (98);
    }

    len1 = strlen(argv[1]);
    len2 = strlen(argv[2]);
    len_res = len1 + len2;
    res = calloc(len_res, sizeof(int));
    if (!res)
    {
        printf("Error\n");
        return (98);
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            res[i + j + 1] += (argv[1][i] - '0') * (argv[2][j] - '0');
        }
    }

    for (i = len_res - 1; i > 0; i--)
    {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }

    if (res[0] == 0)
        i = 1;
    else
        i = 0;

    for (; i < len_res; i++)
        putchar(res[i] + '0');
    putchar('\n');

    free(res);
    return (0);
}

