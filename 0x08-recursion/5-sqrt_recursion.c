#include "holberton.h"

/**
 * find_sqrt - Finds the natural square root of a number
 * @n: Number to find the square root of
 * @guess: Guess for the square root
 *
 * Return: Square root of n, or -1 if no natural square root
 */
int find_sqrt(int n, int guess)
{
    if (guess * guess > n)
        return (-1);
    if (guess * guess == n)
        return (guess);
    return (find_sqrt(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: Number to find the square root of
 *
 * Return: Square root of n, or -1 if no natural square root
 */
int _sqrt_recursion(int n)
{
    if (n < 0)
        return (-1);
    return (find_sqrt(n, 0));
}
