#include "main.h"

/**
 * _strncpy - Copies a string up to n characters
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to copy
 *
 * Return: A pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy characters from src to dest up to n */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* If src is shorter than n, fill remaining space with null bytes */
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

