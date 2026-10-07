#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at a given index
 * @head: address of the list head
 * @index: index of the node to delete
 *
 * Return: 1 on success, or -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *previous;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	previous = NULL;
	while (current != NULL && index > 0)
	{
		previous = current;
		current = current->next;
		index--;
	}
	if (current == NULL)
		return (-1);
	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;
	free(current);
	return (1);
}
