#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data (n) in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of all the data (n) in the list. If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}

