#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * @a: pointer to the first element of the matrix
 * @size: number of rows (and columns) in the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* main diagonal */
		sum1 += a[i * size + i];

		/* other diagonal */
		sum2 += a[i * size + (size - i - 1)];
	}

	printf("%d, %d\n", sum1, sum2);
}

