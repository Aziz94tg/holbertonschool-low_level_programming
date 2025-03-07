#include "main.h"

/**
 * print_number - Prints an integer using only _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	if (n < 0) /* Handle negative numbers */
	{
		_putchar('-');
		n = -n; /* Convert negative to positive */
	}

	if (n / 10) /* If number has more than 1 digit, print recursively */
		print_number(n / 10);

	_putchar((n % 10) + '0'); /* Print the last digit */
}

