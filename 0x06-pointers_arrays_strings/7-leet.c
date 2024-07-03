#include "main.h"

/**
 * leet - Encodes a string into 1337 (leet) format.
 * @str: The string to encode.
 *
 * Return: Pointer to the encoded string.
 */
char *leet(char *str)
{
    int i = 0;
    char leet_map[10] = {'o', 'l', '\0', 'e', 'a', '\0', '\0', 't', '\0', 'r'};

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = leet_map[str[i] - 'a'];
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = leet_map[str[i] - 'A'];
        }
        i++;
    }

    return str;
}
