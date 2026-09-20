#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	const list_t *current;
	size_t count;

	current = h;
	count = 0;

	while (current != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", current->len, current->str);

		current = current->next;
		count++;
	}

	return (count);
}
