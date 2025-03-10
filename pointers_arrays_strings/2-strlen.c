#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0; /* Use tab instead of spaces */

	while (s[len] != '\0') /* Loop through the string */
	{
		len++; /* Increment counter */
	}

	return (len); /* Return the final count */
}

