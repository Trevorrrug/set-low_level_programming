#include "hash_tables.h"

/**
 * key_index - gets the index for a key in a hash table
 * @key: key to locate
 * @size: size of the hash table array
 *
 * Return: index for the key, or 0 if key or size is invalid
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
