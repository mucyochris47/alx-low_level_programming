#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: number of bytes of s2 to concatenate.
 *
 * Return: pointer to the newly allocated space in memory containing s1,
 * followed by the first n bytes of s2, and null terminated. If function
 * fails, it should return NULL. If n is greater or equal to the length
 * of s2, then use the entire string s2. If NULL is passed, treat it as
 * an empty string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concat;
    unsigned int i, j, len1, len2;

    len1 = s1 ? 0 : 0;
    while (s1 && s1[len1])
        len1++;
    len2 = s2 ? 0 : 0;
    while (s2 && s2[len2])
        len2++;

    if (n >= len2)
        n = len2;

    concat = malloc(len1 + n + 1);
    if (!concat)
        return (NULL);

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];
    for (j = 0; j < n; j++)
        concat[i + j] = s2[j];
    concat[i + j] = '\0';

    return (concat);
}

