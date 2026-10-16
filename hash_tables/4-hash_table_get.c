#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value by key
 * @ht: hash table
 * @key: key to find
 *
 * Return: associated value, or NULL when not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || key[0] == '\0' || ht->size == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
