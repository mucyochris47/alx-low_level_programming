#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Counts the number of bits needed to flip to convert
 *             one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor = n ^ m;  // XOR to find differing bits
    unsigned int count = 0;

    while (xor)
    {
        count += xor & 1;  // Increment count if the last bit is 1
        xor >>= 1;         // Shift right to check the next bit
    }

    return count;
}

