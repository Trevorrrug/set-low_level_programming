#include "main.h"
#include <stdlib.h>

/**
 * _strlen - calculates the length of a string
 * @s: string
 *
 * Return: length of string
 */
static unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2
 *
 * Return: pointer to newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (n > len2)
		n = len2;

	result = malloc(sizeof(char) * (len1 + n + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (i = 0; i < n; i++)
		result[len1 + i] = s2[i];

	result[len1 + n] = '\0';

	return (result);
}
