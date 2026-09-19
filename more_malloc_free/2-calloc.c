#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and initializes it to zero
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *bytes;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	bytes = ptr;

	for (i = 0; i < nmemb * size; i++)
		bytes[i] = 0;

	return (ptr);
}
