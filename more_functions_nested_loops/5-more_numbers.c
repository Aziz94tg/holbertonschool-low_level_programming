#include "main.h"

/**
 * more_numbers - Prints numbers from 0 to 14, ten times.
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++) /* Repeat 10 times */
	{
		for (j = 0; j <= 14; j++) /* Print numbers 0 to 14 */
		{
			if (j > 9) /* Print two-digit numbers */
				_putchar('1');

			_putchar((j % 10) + '0'); /* Print the last digit */
		}
		_putchar('\n'); /* New line after each sequence */
	}
}

