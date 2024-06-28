#include <stdio.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a given number
 * @n: The number to find the largest prime factor of
 *
 * Return: The largest prime factor of @n
 */
long largest_prime_factor(long n)
{
    long largest = -1;  // Variable to store the largest prime factor

    // Check for number of 2s in @n
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers
    for (long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2)
        largest = n;

    return

