#include "main.h"

/**
 * _memcpy - Copy memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to destination memory area @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];

    return dest;
}
