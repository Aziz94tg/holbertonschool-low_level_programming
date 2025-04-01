#include "main.h"
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int n;

	if (argc != 3)
	{
		char error[] = "Error\n";

		for (n = 0; error[n] != '\0'; n++)
			_putchar(error[n]);
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = a * b;

	if (result / 10 != 0)
		_putchar((result / 10) + '0');
	_putchar((result % 10) + '0');
	_putchar('\n');

	return (0);
}
l.c
