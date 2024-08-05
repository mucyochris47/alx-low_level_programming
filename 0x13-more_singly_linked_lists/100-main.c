#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for testing reverse_listint function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    listint_t *head;
    listint_t *new_node;
    listint_t *reversed;

    head = NULL;

    // Create and add some nodes to the list
    new_node = add_nodeint_end(&head, 1);
    if (new_node == NULL)
        return (EXIT_FAILURE);

    new_node = add_nodeint_end(&head, 2);
    if (new_node == NULL)
        return (EXIT_FAILURE);

    new_node = add_nodeint_end(&head, 3);
    if (new_node == NULL)
        return (EXIT_FAILURE);

    new_node = add_nodeint_end(&head, 4);
    if (new_node == NULL)
        return (EXIT_FAILURE);

    printf("Original list:\n");
    print_listint(head);

    reversed = reverse_listint(&head);

    printf("Reversed list:\n");
    print_listint(reversed);

    free_listint2(&head);

    return (EXIT_SUCCESS);
}

