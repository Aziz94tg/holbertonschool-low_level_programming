#include "main.h"

/**
 * _memcpy - Copies memory area from src to dest
 * @dest: Where we want to copy to
 * @src: Where we are copying from
 * @n: Number of bytes to copy
 *
 * Return: Pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	/* Loop through each byte and copy it from src to dest */
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	/* Return the pointer to the destination */
	return (dest);
}

