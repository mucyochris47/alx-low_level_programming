#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes the head node of a linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data of the deleted head node. If the list is empty, return 0.
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int n;

    if (head == NULL || *head == NULL)
        return (0);

    temp = *head; /* Store the current head node */
    *head = (*head)->next; /* Move the head to the next node */
    n = temp->n; /* Store the data of the head node */
    free(temp); /* Free the memory of the old head node */

    return (n);
}

