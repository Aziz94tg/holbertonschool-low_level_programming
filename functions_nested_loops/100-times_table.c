#include "main.h"
#include <stdio.h>

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

			/* Print product with proper spacing */
			if (col == 0)
				printf("%d", product);
			else
				printf(", %3d", product); /* Format spacing for alignment */
		}
		printf("\n"); /* Move to next line after each row */
	}
}
