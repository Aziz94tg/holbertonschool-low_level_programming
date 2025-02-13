#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * betty style doc for function main goes there
 * main - Entry point
 * Description: print the last digit of the number stored in the variable n
 * Return: always 0
 */
int main(void)
{
	int n, last_digit;
/* Generate a random number */
	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* Calculate the last digit */
	last_digit = n % 10;

	/* Print the last digit */
	printf("Last digit of %d is %d", n, last_digit);

	if (last_digit > 5)
	{
		printf(" and is greater than 5\n");
	}
	else if (last_digit == 0)
	{
		printf(" and is 0\n");
	}
	else
	{
		printf(" and is less than 6 and not 0\n");
	}

	return (0);
}
