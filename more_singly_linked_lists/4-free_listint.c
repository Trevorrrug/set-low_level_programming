#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees all nodes in a list
 * @head: pointer to the first node
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
