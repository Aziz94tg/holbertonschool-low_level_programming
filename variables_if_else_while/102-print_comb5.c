#include <stdio.h>


/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0
 */


int main(void)
{
	int i, j;

	for (i = 0; i <= 98; i++)
	{
		for (j = i + 1; j <= 99; j++)
		{
			putchar('0' + (i / 10));
			putchar('0' + (i % 10));
			putchar(' ');
			putchar('0' + (j / 10));
			putchar('0' + (j % 10));

			if (i != 98 || j != 99)
			{
				putchar(',');
				putchar(' ');
				}
		}
	}

	putchar ('\n');
	return (0);
}
