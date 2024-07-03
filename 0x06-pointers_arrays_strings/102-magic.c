#include <stdio.h>

/**
 * main - a function that prints a[2] = 98, followed by a new line.
 * Return: Always 0.
 */
int main(void)
{
    int a[5];
    int *p;

    a[2] = 98;
    p = &a[2];
    /* write your line of code here */
    printf("a[2] = %d\n", *(p));
    return (0);
}
