#include "main.h"

/**
 * _strchr - Locate character in string
 * @s: String to search
 * @c: Character to find
 *
 * Return: Pointer to the first occurrence of @c in @s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        s++;
    }

    if (c == '\0')
        return s;

    return NULL;
}
