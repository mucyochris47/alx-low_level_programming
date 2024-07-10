#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: The string to calculate the length of
 *
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome_util - Utility function to check if a string is palindrome
 * @s: The string to check
 * @start: Starting index of the string
 * @end: Ending index of the string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome_util(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (is_palindrome_util(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is palindrome
 * @s: The string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s) - 1;

	return (is_palindrome_util(s, 0, len));
}
