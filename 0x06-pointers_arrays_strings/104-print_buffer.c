#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer 10 bytes per line
 * @b: the buffer to print
 * @size: the size of the buffer
 */
void print_buffer(char *b, int size)
{
    int i, j;

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
                printf("%02x", b[i + j]);
            else
                printf("  ");

            if (j % 2)
                putchar(' ');
        }
        for (j = 0; j < 10 && i + j < size; j++)
        {
            if (b[i + j] >= ' ' && b[i + j] <= '~')
                putchar(b[i + j]);
            else
                putchar('.');
        }
        if (i >= size - 10)
            putchar('\n');
    }
}
