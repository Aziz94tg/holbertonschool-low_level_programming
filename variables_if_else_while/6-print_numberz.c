#include <stdio.h>

/**
 * main - Entry Point
 *
 * Description: Write a program that prints all single
 * digit numbers of base 10 starting from 0
 *
 * Return: Always 0
 */

int main(void)
{
	int num;

	/* Loop through ASCII values of digits 0-9 */
	for (num = 48; num <= 57; num++)
	{
		putchar(num);
	}

	/* Print newline */
	putchar('\n');

	return (0);
}
