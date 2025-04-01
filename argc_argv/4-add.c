#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if digits only, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (!is_digit(argv[i]))
		{
			char e[] = "Error\n";
			int j = 0;

			while (e[j])
				_putchar(e[j++]);
			return (1);
		}
		sum += atoi(argv[i]);
	}
	print_number(sum);
	_putchar('\n');
	return (0);
}

