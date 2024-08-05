#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the pointer to the head of the list.
 * @idx: Index where the new node should be added.
 * @n: Data to insert in the new node.
 *
 * Return: Address of the new node, or NULL if it failed or index is out of range.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp = *head;
    unsigned int i;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    for (i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->next;

    if (temp == NULL || (temp->next == NULL && i < idx - 1))
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);
}

