#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Array to search in
 * @size: Number of elements in the array
 * @cmp: Pointer to the function to use to compare values
 *
 * Return: Index of the first element for which cmp function does not return 0,
 *         -1 if no elements match or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (array && cmp)
    {
        for (i = 0; i < size; i++)
        {
            if (cmp(array[i]))
                return i;
        }
    }

    return -1;
}

