#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
    char c;

    char d;


    c = 'a';
    d = 'A';
    while (c <= 'z')
    {
        putchar(c);  // Print lowercase letter
        c++;         // Move to the next letter
    }

    d = 'A';
    while (d <= 'Z')
    {
        putchar(d);  // Print uppercase letter
        d++;         // Move to the next letter
    }

    putchar('\n');  // Print newline at the end

    return (0);
}
