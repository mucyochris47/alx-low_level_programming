#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, separated by comma and space
 *
 * Return: Always 0
 */
int main(void)
{
    int first = 1, second = 2, next;
    int count;

    printf("%d, %d", first, second); /* Print the first two Fibonacci numbers */

    for (count = 3; count <= 50; ++count)
    {
        next = first + second;
        printf(", %d", next);

        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}
