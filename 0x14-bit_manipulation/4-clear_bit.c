#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Clears the value of a bit at a given index (sets it to 0).
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    *n &= ~(1UL << index);
    return (1);
}

