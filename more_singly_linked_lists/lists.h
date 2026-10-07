#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list node
 * @n: integer value
 * @next: points to the next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int _putchar(char c);
int sum_listint(listint_t *head);
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif
