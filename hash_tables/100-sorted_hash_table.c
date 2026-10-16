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
	shash_node_t *node, *new_node, *sorted;
	char *new_value;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL ||
	    ht->size == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = shash_copy_string(value);
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
	new_node->key = shash_copy_string(key);
	new_node->value = shash_copy_string(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	new_node->sprev = NULL;
	new_node->snext = NULL;
	sorted = ht->shead;
	while (sorted != NULL && strcmp(sorted->key, key) < 0)
		sorted = sorted->snext;
	if (sorted == NULL)
	{
		new_node->sprev = ht->stail;
		if (ht->stail != NULL)
			ht->stail->snext = new_node;
		else
			ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		new_node->snext = sorted;
		new_node->sprev = sorted->sprev;
		if (sorted->sprev != NULL)
			sorted->sprev->snext = new_node;
		else
			ht->shead = new_node;
		sorted->sprev = new_node;
	}
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
