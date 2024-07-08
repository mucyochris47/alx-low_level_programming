#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: String to search
 * @accept: Bytes to search for
 *
 * Return: Pointer to the byte in @s that matches one of the bytes in @accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s)
    {
        char *a = accept;
        while (*a)
        {
            if (*s == *a)
                return s;
            a++;
        }
        s++;
    }
    return NULL;
}