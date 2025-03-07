#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle using `#`
 * @size: The size of the triangle (height and width)
 */
void print_triangle(int size)
{
	int i, j;

	if (size > 0) /* Only print if size is greater than 0 */
	{
		for (i = 0; i < size; i++) /* Loop for each row */
		{
			for (j = 0; j < (size - i - 1); j++) /* Print spaces */
				_putchar(' ');

			for (j = 0; j <= i; j++) /* Print `#` */
				_putchar('#');

			_putchar('\n'); /* Move to the next row */
		}
	}
	else
	{
		_putchar('\n'); /* If size is 0 or negative, print only a newline */
	}
}

