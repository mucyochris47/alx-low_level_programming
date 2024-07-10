#include "main.h"

/**
 * is_prime_util - Utility function to check if a number is prime
 * @n: The number to check
 * @i: The divisor to check against
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_util(int n, int i)
{
	if (n <= 2)
		return (n == 2);

	if (n % i == 0)
		return (0);
	if (i * i > n)
		return (1);
	return (is_prime_util(n, i + 1));
}

/**
 * is_prime_number - Checks if a number is prime
 * @n: The number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_prime_util(n, 2));
}
