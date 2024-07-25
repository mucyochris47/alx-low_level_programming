#include "function_pointers.h"

/**
 * print_name - Prints a name using a given printing function
 * @name: Name to print
 * @f: Pointer to a function that prints a name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}

