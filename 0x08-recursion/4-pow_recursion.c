#include "main.h"

/**
 * _pow_recursion - Computes the power of a number
 * @x: Base number
 * @y: Exponent
 *
 * Return: x raised to the power of y, -1 if y is less than 0
 *
 * Description: Uses recursion to compute power.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
