#include "lists.h"

/**
 * list_len - returns the number of elements in a list_t list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	const list_t *current;
	size_t count;

	current = h;
	count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
