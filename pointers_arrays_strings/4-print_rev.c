#include "main.h"

/**
 * print_rev - Prints a string in reverse followed by a new line
 * @s: Pointer to the string
 */
void print_rev(char *s)
{
	int len = 0;

	/* Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Print the string in reverse */
	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}

	/* Print a new line */
	_putchar('\n');
}

