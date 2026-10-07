#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at a given index
 * @head: address of the list head
 * @idx: index where the new node is inserted
 * @n: value stored in the new node
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *current;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current = *head;
	i = 0;
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
