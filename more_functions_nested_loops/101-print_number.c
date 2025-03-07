#include "main.h"

/**
 * print_number - Prints an integer using only _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n; /* Convert to unsigned int to handle INT_MIN safely */
	}
	else
	{
		num = n;
	}

	if (num / 10) /* Print remaining digits */
		print_number(num / 10);

	_putchar((num % 10) + '0'); /* Print last digit */
}

