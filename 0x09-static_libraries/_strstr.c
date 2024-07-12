#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to locate
 *
 * Return: pointer to the beginning of the located substring, or NULL if the
 * substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
    while (*haystack)
    {
        char *start = haystack;
        char *sub = needle;

        while (*haystack && *sub && *haystack == *sub)
        {
            haystack++;
            sub++;
        }

        if (!*sub)
            return start;

        haystack = start + 1;
    }

    return NULL;
}
