#include <stdio.h>
#include <math.h>

/**
 * main - Finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    long number = 612852475143;
    long largest_factor = 0;
    long i;

    /* Step 1: Remove all factors of 2 */
    while (number % 2 == 0)
    {
        largest_factor = 2;
        number /= 2;
    }

    /* Step 2: Remove all odd factors */
    for (i = 3; i <= sqrt(number); i += 2)
    {
        while (number % i == 0)
        {
            largest_factor = i;
            number /= i;
        }
    }

    /* Step 3: If number > 2, it's a prime factor */
    if (number > 2)
        largest_factor = number;

    /* Step 4: Print the largest prime factor */
    printf("%ld\n", largest_factor);
    return (0);
}

