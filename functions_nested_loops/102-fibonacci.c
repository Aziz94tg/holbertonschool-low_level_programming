#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, next;
	int count;

	printf("%ld, %ld", a, b); /* Print first two numbers */

	for (count = 3; count <= 50; count++) /* Loop from 3rd to 50th Fibonacci */
	{
		next = a + b; /* Compute next Fibonacci number */
		printf(", %ld", next);

		a = b;  /* Update previous two numbers */
		b = next;
	}

	printf("\n"); /* Print newline at the end */
	return (0);
}

