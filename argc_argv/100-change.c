#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints an integer using _putchar
 * @n: number to print
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - prints the minimum number of coins for change
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int values[] = {25, 10, 5, 2, 1}, i;

	if (argc != 2)
	{
		char e[] = "Error\n";
		int j = 0;

		while (e[j])
			_putchar(e[j++]);
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents <= 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		while (cents >= values[i])
		{
			cents -= values[i];
			coins++;
		}
	}

	print_number(coins);
	_putchar('\n');
	return (0);
}

