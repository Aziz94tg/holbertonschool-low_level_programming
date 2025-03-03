#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a = 1, b = 2, next;
	unsigned long int a_high, a_low, b_high, b_low, next_high, next_low;
	int count;

	/* Print first two Fibonacci numbers */
	printf("%lu, %lu", a, b);

	/* Print Fibonacci numbers up to F(90) using normal addition */
	for (count = 3; count <= 90; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	/* Split numbers into high and low parts (handling large numbers) */
	a_high = a / 1000000000; /* Extract high part */
	a_low = a % 1000000000;  /* Extract low part */
	b_high = b / 1000000000;
	b_low = b % 1000000000;

	/* Continue Fibonacci sequence from F(91) to F(98) */
	for (; count <= 98; count++)
	{
		next_high = a_high + b_high; /* Compute high part */
		next_low = a_low + b_low;     /* Compute low part */

		/* Handle overflow in the low part */
		if (next_low >= 1000000000)
		{
			next_high += 1; /* Carry over to high part */
			next_low -= 1000000000;
		}

		/* Print Fibonacci number */
		printf(", %lu%09lu", next_high, next_low);

		/* Update previous numbers */
		a_high = b_high;
		a_low = b_low;
		b_high = next_high;
		b_low = next_low;
	}

	printf("\n"); /* Print newline */
	return (0);
}

