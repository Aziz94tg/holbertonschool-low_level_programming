#include <stdio.h>

/**
 * main - Computes and prints the sum of all multiples of 3 or 5 below 1024
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num, sum = 0;

	for (num = 0; num < 1024; num++) /* Loop through numbers from 0 to 1023 */
	{
		if (num % 3 == 0 || num % 5 == 0) /* Check if num is a multiple of 3 or 5 */
			sum += num; /* Add to sum */
	}

	printf("%d\n", sum); /* Print the result */
	return (0);
}
