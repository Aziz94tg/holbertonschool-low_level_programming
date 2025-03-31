#include "main.h"

/**
 * main - prints the number of arguments passed to the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int n = argc - 1;
	(void)argv;

	if (n / 10 != 0)
		_putchar((n / 10) + '0');
	_putchar((n % 10) + '0');
	_putchar('\n');

	return (0);
}

