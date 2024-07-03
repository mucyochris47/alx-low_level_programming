#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes from src to dest.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: Pointer to the destination string `dest`.
 */
char *_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    for ( ; i < n; i++)
    {
        dest[i] = '\0';
    }

    return dest;
}
