#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
    char *saved = dest;

    while (*dest)
        dest++;

    while ((*dest++ = *src++))
        ;

    return saved;
}

