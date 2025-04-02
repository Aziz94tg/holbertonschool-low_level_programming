#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string to a newly allocated memory
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];

	copy[len] = '\0';
	return (copy);
}

