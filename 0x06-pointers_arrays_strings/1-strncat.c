#include "main.h"

/**
 * _strncat - Concatenates two strings, with n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes from src to concatenate.
 *
 * Return: Pointer to the destination string `dest`.
 */
char *_strncat(char *dest, const char *src, int n)
{
    int dest_len = 0;
    int i = 0;

    // Find the length of dest
    while (dest[dest_len] != '\0')
        dest_len++;

    // Concatenate src to dest
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0'; // Null-terminate the concatenated string

    return dest;
}
