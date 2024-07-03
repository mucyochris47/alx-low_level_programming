#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 0 if s1 and s2 are equal,
 *         negative integer if s1 is less than s2,
 *         positive integer if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }

    return s1[i] - s2[i];
}
