#include <stdio.h>

/**
 * main - Finds and prints the sum of even Fibonacci numbers
 *        whose values do not exceed 4,000,000.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, next;
	long int sum = 2; /* Start with 2 because it's the first even Fibonacci */

	while (1) /* Infinite loop (until we break) */
	{
		next = a + b; /* Generate next Fibonacci number */

		if (next > 4000000) /* Stop when exceeding 4,000,000 */
			break;

		if (next % 2 == 0) /* If number is even, add to sum */
			sum += next;

		/* Update previous Fibonacci numbers */
		a = b;
		b = next;
	}

	printf("%ld\n", sum); /* Print the final sum */
	return (0);
}
