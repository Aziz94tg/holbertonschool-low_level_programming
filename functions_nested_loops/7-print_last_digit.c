#include "main.h"

/**
 * print_last_digit - Prints and returns the last digit of a number
 * @n: The number to extract the last digit from
 *
 * Return: The last digit of the number
 */
int print_last_digit(int n)
{
	int last_digit;
	last_digit = n % 10;  /* Get last digit */
	if (last_digit < 0)   /* Ensure it's positive */
		last_digit = -last_digit;

	_putchar('0' + last_digit); /* Print the digit */
	return (last_digit);
}
