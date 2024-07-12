#include "main.h"

/**
 * _strncat - concatenates two strings (with n bytes from src)
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to concatenate from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
    char *saved = dest;

    while (*dest)
        dest++;

    while (n-- > 0 && (*dest++ = *src++))
        ;

    *dest = '\0';

    return saved;
}
