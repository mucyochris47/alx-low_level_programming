#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be capitalized.
 *
 * Return: Pointer to the capitalized string.
 */
char *cap_string(char *str)
{
    int i = 0;

    /* Capitalize the first letter if it's a lowercase letter */
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - 32;  /* 'a' is 97, 'A' is 65, difference is 32 */
    }

    while (str[i] != '\0')
    {
        /* Check for separators where words start */
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
            str[i] == ',' || str[i] == ';' || str[i] == '.' ||
            str[i] == '!' || str[i] == '?' || str[i] == '"' ||
            str[i] == '(' || str[i] == ')' || str[i] == '{' || 
            str[i] == '}')
        {
            /* If next character is lowercase, capitalize it */
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
            {
                str[i + 1] = str[i + 1] - 32;
            }
        }
        i++;
    }

    return str;
}
