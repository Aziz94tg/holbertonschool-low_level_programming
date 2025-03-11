#include "main.h"

/**
 * puts_half - Print the second half of a string
 * @str: The string to be printed
 *
 * Return: void
 */

void puts_half(char *str)
{
	int length = 0, start, i;

	/* Find the length of the string */
	while (str[length] != '\0')
		length++;

	/* Calculate the string index for the second half */
	if (length % 2 == 0)
	{
		start = length / 2;
	}
	else
	{
		start = (length + 1) / 2;
	}

	/* Print the charcaters from the start index */
	for (i = start; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}
