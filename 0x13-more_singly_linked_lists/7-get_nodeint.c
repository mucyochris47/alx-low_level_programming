#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the node at a specific index.
 * @head: Pointer to the head of the list.
 * @index: The index of the node to retrieve.
 *
 * Return: The node at the specified index. If the node does not exist, return NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head != NULL; i++)
    {
        if (i == index)
            return (head);
        head = head->next;
    }

    return (NULL);
}

