#include "lists.h"

/**
 * reverse_listint - reverses a singly linked list
 * @head: address of the first node pointer
 *
 * Return: pointer to the new first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous;
	listint_t *next;

	if (head == NULL)
		return (NULL);
	previous = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}
	*head = previous;
	return (previous);
}
