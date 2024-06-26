#include <stdio.h>

/**
 * main - Entry point
 *
 * This function calculates the sum of all natural numbers below 1024
 * that are multiples of 3 or 5, and prints the result.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int limit = 1024;
    int sum = 0;
    int i;

    for (i = 1; i < limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return (0);
}
