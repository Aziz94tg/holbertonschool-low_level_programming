#include "main.h"

/**
 * main - prints the program name
 * @argc: argument count
 * @argv: argument vector (array of arguments)
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i = 0;

	(void)argc;

	while (argv[0][i] != '\0')
	{
		_putchar(argv[0][i]);
		i++;
	}
	_putchar('\n');

	return (0);
}

