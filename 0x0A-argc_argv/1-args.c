#include "main.h"

/**
 * main - prints number of arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;

	if (argc > 1)
	{
		int n = argc - 1;
		if (n >= 10)
		{
			_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
		}
		else
		{
			_putchar(n + '0');
		}
	}
	else
	{
		_putchar('0');
	}

	_putchar('\n');
	return (0);
}
