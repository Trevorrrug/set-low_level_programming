#include "main.h"
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: arguments
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int a, b;
	int res;

	if (argc != 3)
	{
		char err[] = "Error\n";
		int i = 0;

		while (err[i])
		{
			_putchar(err[i]);
			i++;
		}
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	res = a * b;

	/* print number */
	if (res == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	if (res < 0)
	{
		_putchar('-');
		res = -res;
	}

	if (res >= 10)
		_putchar((res / 10) + '0');

	_putchar((res % 10) + '0');
	_putchar('\n');

	return (0);
}
