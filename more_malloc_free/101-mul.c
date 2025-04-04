#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: input string
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_result - prints an int array as a number
 * @res: result array
 * @size: size of the array
 */
void print_result(int *res, int size)
{
	int i = 0, started = 0;

	for (i = 0; i < size; i++)
	{
		if (res[i] != 0)
			started = 1;
		if (started)
			_putchar(res[i] + '0');
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, total_len, i, j, n1, n2, carry;
	int *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		write(2, "Error\n", 6);
		exit(98);
	}

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	total_len = len1 + len2;
	result = calloc(total_len, sizeof(int));
	if (!result)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = argv[1][i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	print_result(result, total_len);
	free(result);
	return (0);
}

