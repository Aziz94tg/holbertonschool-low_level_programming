#include "main.h"

/**
 * print_alphabet_x10 - print the alphabet 10 times
 * Return: Always 0
 */




void print_alphabet_x10(void)
{
	char letter;
	int a = 0;
	while ( a < 10)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);

		_putchar('\n');
		a++;
	}
}
