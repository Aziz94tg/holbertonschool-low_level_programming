#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @num: The number to print
 */
void print_number(int num)
{
	if (num >= 10) /* Handle two-digit numbers */
		print_number(num / 10);
	_putchar((num % 10) + '0'); /* Print last digit */
}

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The number for the times table (0 ≤ n ≤ 15)
 */
void print_times_table(int n)
{
	int row, col, product;

	if (n < 0 || n > 15) /* Validate n */
		return;

	for (row = 0; row <= n; row++) /* Loop through rows */
	{
		for (col = 0; col <= n; col++) /* Loop through columns */
		{
			product = row * col;

			if (col != 0) /* Formatting for spacing */
			{
				_putchar(',');
				_putchar(' ');

				/* Add extra space for proper alignment */
				if (product < 10)
					_putchar(' ');
				if (product < 100)
					_putchar(' ');
			}

			print_number(product); /* Print the number */
		}
		_putchar('\n'); /* Move to next line after each row */
	}
}

