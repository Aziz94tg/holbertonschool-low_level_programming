#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints an integer
 * @n: number to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		char e[] = "Error\n";
		int i = 0;

		while (e[i])
			_putchar(e[i++]);
		return (1);
	}

	a = atoi(argv[1]) * atoi(argv[2]);
	print_number(a);
	_putchar('\n');
	return (0);
}

