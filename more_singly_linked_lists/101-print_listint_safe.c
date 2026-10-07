#include <stdlib.h>
#include "lists.h"

/**
 * print_unsigned - prints an unsigned integer in decimal
 * @number: number to print
 */
static void print_unsigned(size_t number)
{
	if (number >= 10)
		print_unsigned(number / 10);
	_putchar((char)('0' + number % 10));
}

/**
 * print_hex - prints an unsigned integer in hexadecimal
 * @number: number to print
 */
static void print_hex(size_t number)
{
	char digit;

	if (number >= 16)
		print_hex(number / 16);
	digit = (char)(number % 16);
	_putchar(digit < 10 ? '0' + digit : 'a' + digit - 10);
}

/**
 * print_node - prints a node address and value
 * @node: node to print
 */
static void print_node(const listint_t *node)
{
	_putchar('[');
	_putchar('0');
	_putchar('x');
	print_hex((size_t)node);
	_putchar(']');
	_putchar(' ');
	if (node->n < 0)
	{
		_putchar('-');
		print_unsigned((size_t)(-(long int)node->n));
	}
	else
		print_unsigned((size_t)node->n);
	_putchar('\n');
}

/**
 * remember_node - stores a node address unless already stored
 * @nodes: address of the visited-node array
 * @count: number of stored addresses
 * @capacity: capacity of the array
 * @node: node address to store
 *
 * Return: 1 if already stored, 0 if stored, or -1 on allocation failure
 */
static int remember_node(const listint_t ***nodes, size_t *count,
		size_t *capacity, const listint_t *node)
{
	size_t i;
	size_t new_capacity;
	const listint_t **larger;

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
		free((void *)*nodes);
		*nodes = larger;
		*capacity = new_capacity;
	}
	(*nodes)[(*count)++] = node;
	return (0);
}

/**
 * print_listint_safe - prints each node in a list, including cyclic lists
 * @head: pointer to the first node
 *
 * Return: number of unique nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t **nodes = NULL;
	const listint_t *current = head;
	size_t count = 0;
	size_t capacity = 0;
	int result;

	while (current != NULL)
	{
		result = remember_node(&nodes, &count, &capacity, current);
		if (result == -1)
		{
			free((void *)nodes);
			exit(98);
		}
		if (result == 1)
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			print_node(current);
			break;
		}
		print_node(current);
		current = current->next;
	}
	free((void *)nodes);
	return (count);
}
