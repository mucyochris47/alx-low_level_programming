#include <stdio.h>

/**
 * main - Entry point
 *
 * This program prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, separated by commas and spaces.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int count = 50;  // Number of Fibonacci numbers to print
    int first = 1, second = 2;
    int next, i;

    // Print the first two Fibonacci numbers manually
    printf("%d, %d", first, second);

    // Generate and print the remaining Fibonacci numbers
    for (i = 3; i <= count; i++)
    {
        next = first + second;
        printf(", %d", next);
        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}
