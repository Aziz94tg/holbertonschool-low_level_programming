#include "main.h"

/**
 * _puts - Prints a string followed by a new line
 * @str: Pointer to the string
 */
void _puts(char *str)
{
	while (*str) /* Loop until we reach null terminator */
	{
		_putchar(*str); /* Print the current character */
		str++; /* Move to the next character */
	}
	_putchar('\n'); /* Print a new line after the string */
}

