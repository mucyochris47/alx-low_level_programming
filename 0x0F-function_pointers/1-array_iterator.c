#include "function_pointers.h"
#include <stddef.h>  /* for size_t */

/**
 * array_iterator - Executes a function given as a parameter
 *                  on each element of an array.
 * @array: Array to iterate over
 * @size: Size of the array
 * @action: Pointer to the function to use
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    if (array && action)
    {
        for (i = 0; i < size; i++)
        {
            action(array[i]);
        }
    }
}

