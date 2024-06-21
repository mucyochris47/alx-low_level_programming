#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
    char letter;

    letter = 'a';
    while (letter <= 'z')
    {
        putchar(letter);  // Print lowercase letter
        letter++;         // Move to the next letter
    }

    letter = 'A';
    while (letter <= 'Z')
    {
        putchar(letter);  // Print uppercase letter
        letter++;         // Move to the next letter
    }

    putchar('\n');  // Print newline at the end

    return (0);
}
