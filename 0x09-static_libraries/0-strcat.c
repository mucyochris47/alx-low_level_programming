#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source string to append
 *
 * Return: pointer to the destination buffer @dest
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    while (*dest)
        dest++;

    while ((*dest++ = *src++))
        ;

    return ptr;
}
