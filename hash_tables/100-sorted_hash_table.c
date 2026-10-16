#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_copy_string - duplicates a string
 * @str: string to copy
 *
 * Return: pointer to the copy, or NULL on failure
 */
static char *shash_copy_string(const char *str)
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
 * shash_find_node - finds a key in a bucket
 * @ht: sorted hash table
 * @index: bucket index
 * @key: key to find
 *
 * Return: matching node, or NULL if it is not present
 */
static shash_node_t *shash_find_node(shash_table_t *ht,
				     unsigned long int index, const char *key)
{
	shash_node_t *node;

	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (node);
	}
	return (NULL);
}

/**
 * shash_create_node - allocates and initializes a node
 * @key: key to copy
 * @value: value to copy
 *
 * Return: new node, or NULL on allocation failure
 */
static shash_node_t *shash_create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->key = shash_copy_string(key);
	node->value = shash_copy_string(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;
	return (node);
}

/**
 * shash_link_sorted - inserts a node into the sorted list
 * @ht: sorted hash table
 * @node: node to link
 */
static void shash_link_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	current = ht->shead;
	while (current != NULL && strcmp(current->key, node->key) < 0)
		current = current->snext;
	if (current == NULL)
	{
		node->sprev = ht->stail;
		if (ht->stail != NULL)
			ht->stail->snext = node;
		else
			ht->shead = node;
		ht->stail = node;
		return;
	}
	node->snext = current;
	node->sprev = current->sprev;
	if (current->sprev != NULL)
		current->sprev->snext = node;
	else
		ht->shead = node;
	current->sprev = node;
}

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(*table));
	if (table == NULL)
		return (NULL);
	table->array = malloc(sizeof(*(table->array)) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		table->array[i] = NULL;
	table->size = size;
	table->shead = NULL;
	table->stail = NULL;
	return (table);
}

/**
 * shash_table_set - inserts or updates a sorted hash table entry
 * @ht: sorted hash table
 * @key: non-empty key
 * @value: value associated with the key
 *
 * Return: 1 on success, or 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	char *new_value;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL ||
	    ht->size == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = shash_find_node(ht, index, key);
	if (node != NULL)
	{
		new_value = shash_copy_string(value);
		if (new_value == NULL)
			return (0);
		free(node->value);
		node->value = new_value;
		return (1);
	}
	node = shash_create_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	shash_link_sorted(ht, node);
	return (1);
}

/**
 * shash_table_get - retrieves a sorted hash table value
 * @ht: sorted hash table
 * @key: key to find
 *
 * Return: associated value, or NULL when not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

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

/**
 * shash_table_print - prints entries in ascending key order
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first;

	if (ht == NULL)
		return;
	printf("{");
	first = 1;
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints entries in descending key order
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first;

	if (ht == NULL)
		return;
	printf("{");
	first = 1;
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table and its entries
 * @ht: sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node != NULL)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
	free(ht->array);
	free(ht);
}
