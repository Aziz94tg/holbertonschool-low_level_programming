#include <stdio.h>

/**
 * main - Entry Point
 *
 * Description: Prints the lowercase alphabet in reverse
 *
 * Return: Always 0
 */

int main(void)
{
	int letter;

	/* Loop through letters from 'z' to 'a' */
	for (letter = 'z'; letter >='a'; letter--)
	{
		putchar(letter);
	}

	/* Print newline */
	putchar('\n');

	return (0);
}
