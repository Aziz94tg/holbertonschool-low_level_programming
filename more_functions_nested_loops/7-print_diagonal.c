#include "main.h"

/**
 * print_diagonal - Draws a diagonal line using `\`
 * @n: Number of times `\` should be printed
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0) /* Only draw if n is greater than 0 */
	{
		for (i = 0; i < n; i++) /* Loop to create n lines */
		{
			for (j = 0; j < i; j++) /* Print leading spaces */
				_putchar(' ');

			_putchar('\\'); /* Print the diagonal character */
			_putchar('\n'); /* Move to the next line */
		}
	}
	else
	{
		_putchar('\n'); /* Print only a newline if n <= 0 */
	}
}
 
