#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - removes the first node and returns its value
 * @head: address of the list head
 *
 * Return: removed value, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *first;
	int value;

	if (head == NULL || *head == NULL)
		return (0);
	first = *head;
	value = first->n;
	*head = first->next;
	free(first);
	return (value);
}
