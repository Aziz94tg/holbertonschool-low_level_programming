#include "main.h"

/**
 * print_square - Prints a square using `#`
 * @size: The size of the square
 */
void print_square(int size)
{
	int i, j;

	if (size > 0) /* Print square only if size is positive */
	{
		for (i = 0; i < size; i++) /* Loop for rows */
		{
			for (j = 0; j < size; j++) /* Loop for columns */
				_putchar('#'); /* Print the character '#' */
			
			_putchar('\n'); /* Move to the next row */
		}
	}
	else
	{
		_putchar('\n'); /* If size <= 0, print only a newline */
	}
}

