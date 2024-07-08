#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String to search
 * @accept: Characters to accept in the prefix
 *
 * Return: Number of bytes in the initial segment of @s which consist only of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int match;

    while (*s)
    {
        match = 0;
        while (*accept)
        {
            if (*s == *accept)
            {
                count++;
                match = 1;
                break;
            }
            accept++;
        }
        if (match == 0)
            break;
        s++;
    }
    return count;
}
