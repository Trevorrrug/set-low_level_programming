#include "lists.h"

/**
 * print_number - prints an integer using _putchar
 * @number: integer to print
 */
static void print_number(long number)
{
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number >= 10)
		print_number(number / 10);
	_putchar((char)('0' + number % 10));
}

/**
 * print_listint - prints all integers in a list
 * @h: pointer to the first node
 *
 * Return: number of nodes printed
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		print_number((long)h->n);
		_putchar('\n');
		h = h->next;
		count++;
	}
	return (count);
}
