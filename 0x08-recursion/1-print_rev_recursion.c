#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse
 * @s: String to be printed in reverse
 *
 * Description: Uses recursion to print each character of
 * the string in reverse order until the null character is reached.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;

	_print_rev_recursion(s + 1); /* Recursively move to end of string */
	_putchar(*s); /* Print current character after recursion */
}
