#include "hash_tables.h"

/**
 * hash_djb2 - computes a hash using the djb2 algorithm
 * @str: string to hash
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	if (str == NULL)
		return (0);
	hash = 5381;
	while ((c = *str++) != '\0')
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
