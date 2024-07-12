#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    char *saved = dest;

    while ((*dest++ = *src++))
        ;

    return saved;
}

