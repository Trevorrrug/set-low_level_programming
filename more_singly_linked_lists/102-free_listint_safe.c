#include <stdlib.h>
#include "lists.h"

/**
 * remember_node - stores a node address unless already stored
 * @nodes: address of the visited-node array
 * @count: number of stored addresses
 * @capacity: capacity of the array
 * @node: node address to store
 *
 * Return: 1 if already stored, 0 if stored, or -1 on allocation failure
 */
static int remember_node(listint_t ***nodes, size_t *count,
		size_t *capacity, listint_t *node)
{
	size_t i;
	size_t new_capacity;
	listint_t **larger;

	for (i = 0; i < *count; i++)
		if ((*nodes)[i] == node)
			return (1);
	if (*count == *capacity)
	{
		new_capacity = *capacity == 0 ? 16 : *capacity * 2;
		if (new_capacity < *capacity ||
		    new_capacity > (size_t)-1 / sizeof(*larger))
			return (-1);
		larger = malloc(new_capacity * sizeof(*larger));
		if (larger == NULL)
			return (-1);
		for (i = 0; i < *count; i++)
			larger[i] = (*nodes)[i];
		free(*nodes);
		*nodes = larger;
		*capacity = new_capacity;
	}
	(*nodes)[(*count)++] = node;
	return (0);
}

/**
 * free_listint_safe - frees all unique nodes in a possibly cyclic list
 * @h: address of the list head
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t **nodes = NULL;
	listint_t *current;
	size_t count = 0;
	size_t capacity = 0;
	size_t i;
	int result;

	if (h == NULL)
		return (0);
	current = *h;
	while (current != NULL)
	{
		result = remember_node(&nodes, &count, &capacity, current);
		if (result == -1)
		{
			free(nodes);
			exit(98);
		}
		if (result == 1)
			break;
		current = current->next;
	}
	*h = NULL;
	for (i = 0; i < count; i++)
		free(nodes[i]);
	free(nodes);
	return (count);
}
