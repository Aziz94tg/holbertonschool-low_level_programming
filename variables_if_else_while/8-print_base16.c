#include <stdio.h>

/**
 * main - Entry Point
 *
 * Description: Prints all the numbers of base 16 in lowercase
 *
 * Return: Always 0
 */

int main(void)
{
	int num;

	/* Print digits 0-9 */
	for (num = '0'; num <= '9'; num++)
	{
		putchar(num);
	}

	/* Print lowercase letters a-f */
	for (num = 'a'; num <= 'f'; num++)
	{
		putchar(num);
	}

	/* Print newline */
	putchar('\n');

	return (0);
}
