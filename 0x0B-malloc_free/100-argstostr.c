#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the concatenated string, or NULL if failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, len, total_len = 0;
	char *str, *str_ptr;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length of arguments */
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			len++;
		}
		total_len += len + 1; /* +1 for each new line character */
	}

	/* Allocate memory for concatenated string */
	str = malloc((total_len + 1) * sizeof(char)); /* +1 for the terminating null byte */
	if (str == NULL)
		return (NULL);

	str_ptr = str;

	/* Copy arguments to concatenated string */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			*str_ptr = av[i][j];
			str_ptr++;
			j++;
		}
		*str_ptr = '\n'; /* Add newline after each argument */
		str_ptr++;
	}
	*str_ptr = '\0'; /* Terminate the string */

	return (str);
}

