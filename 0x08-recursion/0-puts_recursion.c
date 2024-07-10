#include "main.h"

/**
 * _puts_recursion - Prints a string followed by a new line
 * @s: String to be printed
 *
 * Description: Uses recursion to print each character of
 * the string until the null character is reached.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n'); /* Print newline at the end */
		return;
	}

	_putchar(*s); /* Print current character */
	_puts_recursion(s + 1); /* Move to next character */
}
