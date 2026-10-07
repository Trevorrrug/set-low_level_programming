#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a given index
 * @head: pointer to the first node
 * @index: index of the requested node
 *
 * Return: pointer to the node, or NULL if the index is out of range
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (head != NULL && index > 0)
	{
		head = head->next;
		index--;
	}
	return (head);
}
