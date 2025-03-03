#include "main.h"

/**
 * times_table - Prints the 9 times table from 0
 */
void times_table(void)
{
	int row, col, product;

	for (row = 0; row <= 9; row++) /* Loop through rows */
	{
		for (col = 0; col <= 9; col++) /* Loop through columns */
		{
			product = row * col; /* Compute product */

			if (col != 0) /* Add comma and spacing after first number */
			{
				_putchar(',');
				_putchar(' ');

				/* Add extra space for single-digit numbers */
				if (product < 10)
					_putchar(' ');
			}

			/* Print the number */
			if (product < 10)
				_putchar('0' + product);
			else
			{
				_putchar('0' + (product / 10)); /* Tens digit */
				_putchar('0' + (product % 10)); /* Ones digit */
			}
		}
		_putchar('\n'); /* New line after each row */
	}
}
