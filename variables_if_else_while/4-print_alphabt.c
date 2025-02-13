#include <stdio.h>

/**
 * main - Entry Point
 *
 * Description: Print all the letters except q and e
 *
 * Return: Always 0
 */


int main(void)
{
	char letter;

	/* Loop through lowercase letters from 'a' to 'z' */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter != 'q' && letter != 'e')
			putchar(letter);
	}

	/* Print newline */
	putchar ('\n');

	return(0);
}
