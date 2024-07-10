#include "main.h"

/**
 * factorial - Computes the factorial of a number
 * @n: Number to compute factorial of
 *
 * Return: Factorial of n, -1 if n is less than 0
 *
 * Description: Uses recursion to compute factorial.
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (1);

	return (n * factorial(n - 1));
}
