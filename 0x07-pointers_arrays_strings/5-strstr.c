#include "main.h"
#include <stddef.h> /* Include for NULL definition */

/**
 * _strstr - Locates a substring
 * @haystack: String to search within
 * @needle: Substring to find
 *
 * Return: Pointer to the beginning of the located substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
    char *h, *n;

    while (*haystack)
    {
        h = haystack;
        n = needle;
        while (*h && *n && *h == *n)
        {
            h++;
            n++;
        }
        if (!*n) /* If we reached the end of needle (found the substring) */
            return haystack;

        haystack++;
    }

    return NULL; /* Return NULL if substring not found */
}
