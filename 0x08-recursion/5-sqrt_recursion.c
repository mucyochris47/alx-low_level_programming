#include "main.h"

/**
 * find_sqrt - Helper function to find the square root recursively
 * @n: Number to compute square root of
 * @i: Iterator to test square root value
 *
 * Return: Square root of n, -1 if no natural square root is found
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Computes the natural square root of a number
 * @n: Number to compute square root of
 *
 * Return: Natural square root of n, -1 if n does not have a natural square root
 *
 * Description: Uses recursion to find the square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_sqrt(n, 0));
}
