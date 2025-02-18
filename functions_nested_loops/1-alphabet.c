#include "main.h"

/**
 * print_alphabet - print the alphabet
 *
 * Description: Print alphabet
 *
 * Return: Always 0
 */

void print_alphabet(void)
/** prints the alphabet */
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);

	_putchar('\n');
}
