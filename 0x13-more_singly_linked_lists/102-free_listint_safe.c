#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *temp;
    listint_t *current = *h;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
        count++;
        
        if (temp <= current)
            break;
    }
    
    *h = NULL;

    return (count);
}

