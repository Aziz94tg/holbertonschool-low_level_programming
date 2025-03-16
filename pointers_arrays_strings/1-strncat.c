#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes to use from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0; /* Variable to track the length of dest */
	int i = 0; /* Index for iterating through src */

	/* Find the end of dest */
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* Append up to n characters from src */
	while (i < n && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	/* Null-terminate the result */
	dest[dest_len] = '\0';

	return (dest);
}

