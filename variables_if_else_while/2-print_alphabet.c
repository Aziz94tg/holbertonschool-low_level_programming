#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print the lowercase
 *
 * Return: always 0
 */

int main(void)
{
	char letter;

	/* Loop through lowercase letters */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	/* Print new line */
	putchar('\n');

	return (0);

}
