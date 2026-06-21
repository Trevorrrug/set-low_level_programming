#include "main.h"
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: arguments
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int i, j;
	int sum = 0;

	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		j = 0;

		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				char err[] = "Error\n";
				int k = 0;

				while (err[k])
				{
					_putchar(err[k]);
					k++;
				}
				return (1);
			}
			j++;
		}

		sum += atoi(argv[i]);
	}

	if (sum == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	if (sum >= 10)
		_putchar((sum / 10) + '0');

	_putchar((sum % 10) + '0');
	_putchar('\n');

	return (0);
}
