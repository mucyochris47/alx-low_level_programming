#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc(old_size)
 * @old_size: size of the allocated space for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    unsigned int i;
    unsigned int min_size = old_size < new_size ? old_size : new_size;

    if (new_size == old_size)
        return (ptr);

    if (!ptr)
        return (malloc(new_size));

    if (new_size == 0 && ptr)
    {
        free(ptr);
        return (NULL);
    }

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);

    for (i = 0; i < min_size; i++)
        *((char *)new_ptr + i) = *((char *)ptr + i);

    free(ptr);
    return (new_ptr);
}
  
