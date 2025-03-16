#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: Pointer to the array of integers
 * @n: Number of elements in the array
 *
 * Return: Nothing (void function)
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	/* Loop only through the first half of the array */
	for (i = 0; i < n / 2; i++)
	{
		/* Swap a[i] with a[n - i - 1] */
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}

