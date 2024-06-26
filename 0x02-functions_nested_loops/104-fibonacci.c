#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned long int first = 1, second = 2, next;
    int count;

    printf("%lu, %lu", first, second); /* Print the first two Fibonacci numbers */

    for (count = 3; count <= 98; ++count)
    {
        next = first + second;
        printf(", %lu", next);

        first = second;
        second = next;
    }

    printf("\n");

    return (0);
}
