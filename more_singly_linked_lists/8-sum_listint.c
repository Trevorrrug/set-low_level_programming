#include "lists.h"

/**
 * sum_listint - returns the sum of all node values
 * @head: pointer to the first node
 *
 * Return: sum of the values, or 0 for an empty list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
