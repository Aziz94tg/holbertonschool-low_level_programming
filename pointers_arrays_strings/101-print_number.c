#include "main.h"

/**
 * print number - prints integer 
 * @n: The integer to print
 */

void print_number(int n)
{
	unsigned int num;

	if (n < 0) /* If negative print '-' */
	{
		_putchar('-');
		num = -n;
	}
	else
	{ 
		num = n;
	}

	if (num / 10) /* If more than one digit */
		    print_number(num / 10);
		
		_putchar('0' + (num % 10));
}
