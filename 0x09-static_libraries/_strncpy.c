#include "main.h"

/**
 * _strncpy - copies a string (with n bytes)
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *saved = dest;

    while (n-- > 0 && (*dest++ = *src++))
        ;

    *dest = '\0';

    return saved;
}
