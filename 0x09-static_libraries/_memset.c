#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area to fill
 * @b: byte to fill with
 * @n: number of bytes to fill
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;

    while (n-- > 0)
        *ptr++ = b;

    return s;
}
