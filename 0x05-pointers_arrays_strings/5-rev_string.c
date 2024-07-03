/* File: 5-rev_string.c */
#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
    int len = 0;
    int i;
    char temp;

    /* Calculate length of the string */
    while (s[len] != '\0')
        len++;

    /* Swap characters from the start and end */
    for (i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
