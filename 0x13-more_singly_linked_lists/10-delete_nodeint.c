#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at a given position.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp = *head, *node_to_delete;
    unsigned int i;

    if (temp == NULL)
        return (-1);

    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return (1);
    }

    for (i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return (-1);

    node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);

    return (1);
}

