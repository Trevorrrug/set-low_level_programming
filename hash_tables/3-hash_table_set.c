#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * copy_string - duplicates a string
 * @str: string to copy
 *
 * Return: pointer to the copy, or NULL on failure
 */
static char *copy_string(const char *str)
{
	char *copy;
	size_t len;

	len = strlen(str) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	memcpy(copy, str, len);
	return (copy);
}

/**
 * hash_table_set - adds or updates a key/value pair
 * @ht: hash table
 * @key: non-empty key
 * @value: value to associate with the key
 *
 * Return: 1 on success, or 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *new_node;
	char *new_value;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = copy_string(value);
			if (new_value == NULL)
				return (0);
			free(node->value);
			node->value = new_value;
			return (1);
		}
		node = node->next;
	}
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (0);
	new_node->key = copy_string(key);
	new_node->value = copy_string(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
