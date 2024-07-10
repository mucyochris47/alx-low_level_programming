#include "main.h"

/**
 * is_divisible - Checks if a number is divisible by any number other than 1 and itself
 * @n: The number to check
 * @divisor: The current divisor to check against n
 *
 * Return: 1 if the number is divisible by any other number than 1 and itself,
 *         0 otherwise
 */
int is_divisible(int n, int divisor)
{
	if (n % divisor == 0)
		return (0);
	if (divisor > n / 2)
		return (1);
	return (is_divisible(n, divisor + 1));
}

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 *
 * Description: Uses recursion to check divisibility up to half of n.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	return (is_divisible(n, 2));
}
