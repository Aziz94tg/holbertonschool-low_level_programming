#include "main.h"

/**
 * print number - prints integer 
 * @n: The integer to print
 */

void print_number(int n)
{
	if (n < 0) /* If negative print '-' */
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10) /* If more than one digit */
		    print_number(n / 10);
		
		_putchar('0' + (n % 10));
}
