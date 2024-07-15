#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the newly allocated memory containing a copy of str,
 * or NULL if str is NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
