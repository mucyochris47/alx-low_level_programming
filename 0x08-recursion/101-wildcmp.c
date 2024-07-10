#include "main.h"

/**
 * wildcmp - Compares two strings with support for wildcard '*'
 * @s1: First string to compare
 * @s2: Second string to compare, may contain wildcards '*'
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings reach at the end, return true */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If the first string is empty and the second string contains only '*', return true */
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);

	/* If the first string is empty, but the second string is not, return false */
	if (*s1 == '\0')
		return (0);

	/* If current characters match, compare next characters */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* If the character in the second string is '*', match with s1 characters until a match is found */
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		else if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}

	/* If none of the conditions match, return false */
	return (0);
}
