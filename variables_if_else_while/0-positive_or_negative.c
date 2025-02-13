#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * Description: Generate a random number and print whether
 * it is positive, negative, or zero.
 * Return: always 0
 */
int main(void)
{
	int n;

       	/* Random number generatior */
	srand(time(0));
       	n = rand() - RAND_MAX / 2;
	
	/* Check if the number is positive, negative, or zero */
	if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else
	{
		printf("%d is negative\n", n);
	}

	return (0);
}
