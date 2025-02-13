#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Write a program that prints all single 
 * digit numbers of base 10 starting from 0
 *
 * Return: Always 0
 */

int main(void)
{
	int num;
	/* Loop through digits 0 to 9 */
	for (num = 0; num <= 9; num++)
	{
		printf("%d", num);
	}

	/* Print newline */
	printf("\n");

	return (0);

}
