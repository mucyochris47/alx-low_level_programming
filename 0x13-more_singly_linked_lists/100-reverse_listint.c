#include "lists.h"
#include <stdlib.h>

/**
 * reverse_listint - Reverses a linked list.
 * @head: Pointer to the pointer to the head of the list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return (*head);
}

