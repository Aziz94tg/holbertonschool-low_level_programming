#include <stdio.h>

/**
 * main - Entry Point
 *
 * Description: Prints all possible combinations of single-digit numbers
 *
 * Return: Always 0
 */

int main(void)
{
	int num;

	/* Loop throgh numbers 0-9 */
	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0'); 

		/* Print comma and space for all except the last number */
		if (num < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	/* Print newline */
	putchar('\n');

	return (0);
}
