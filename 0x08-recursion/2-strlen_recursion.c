#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: String to calculate length of
 *
 * Return: Length of the string
 *
 * Description: Uses recursion to count each character
 * until the null terminator is reached.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}
