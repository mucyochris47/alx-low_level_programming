#include <stdio.h>
#include <stdlib.h> /* For atoi() */

/**
 * is_positive_number - Checks if a string is a positive number
 * @s: The string to check
 *
 * Return: 1 if the string is a positive number, 0 otherwise
 */
int is_positive_number(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return 0;
        s++;
    }
    return 1;
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 *
 * Return: 0 if successful, 1 if any argument is not a positive number
 */
int main(int argc, char *argv[])
{
    int i;
    int sum = 0;

    if (argc < 2)
    {
        printf("0\n");
        return 0;
    }

    for (i = 1; i < argc; i++)
    {
        if (is_positive_number(argv[i]))
        {
            sum += atoi(argv[i]);
        }
        else
        {
            printf("Error\n");
            return 1;
        }
    }

    printf("%d\n", sum);

    return 0;
}
