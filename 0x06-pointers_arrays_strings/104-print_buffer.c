#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer in a particular format
 * @b: The buffer to print
 * @size: Number of bytes to print from the buffer
 *
 * Description: Prints the content of a buffer in a specific format:
 *               - 10 bytes per line, each byte printed in hexadecimal
 *                 separated by spaces
 *               - Each line shows the byte number in hexadecimal:
 *                 starting at the position 0 of the buffer
 *               - If the buffer is NULL, nothing is printed
 *               - If size is less or equal to 0, nothing is printed
 */
void print_buffer(char *b, int size)
{
    int i, j;

    if (b == NULL || size <= 0)
        return;

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
                printf("%02x", b[i + j]);
            else
                printf("  ");

            if (j % 2 != 0)
                printf(" ");
        }
        
        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                if (b[i + j] >= 32 && b[i + j] <= 126)
                    printf("%c", b[i + j]);
                else
                    printf(".");
            }
        }
        printf("\n");
    }
}
