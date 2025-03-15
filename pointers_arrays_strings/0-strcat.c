#include "main.h"

/**
 * _strcat - Concatenates (joins) two strings
 * @dest: The destination string (this will be modified)
 * @src: The source string (this will be added to dest)
 *
 * Return: A pointer to the resulting string (dest)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0; /* Find the end of dest */
	int j = 0; /* Start at the beginning of src */

	/* Find where dest ends */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Copy each character from src to dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0'; /* Add null terminator */

	return (dest); /* Betty requires parentheses */
}

