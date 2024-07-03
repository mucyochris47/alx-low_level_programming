#include "main.h"

/**
 * string_toupper - Changes all lowercase letters of a string to uppercase.
 * @str: The string to be converted.
 *
 * Return: Pointer to the converted string.
 */
char *string_toupper(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;  /* Convert lowercase to uppercase */
        }
        i++;
    }

    return str;
}
