#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a node at the beginning of a list
 * @head: address of the list head
 * @n: value stored in the new node
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
