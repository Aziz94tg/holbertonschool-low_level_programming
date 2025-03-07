#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9, except 2 and 4.
 */
void print_most_numbers(void)
{
	char numbers[] = "01356789"; /* Store valid numbers in a string */
	int i = 0;

	while (numbers[i] != '\0') /* Loop through the string */
	{
		_putchar(numbers[i]);
		i++;
	}
	_putchar('\n'); /* Print newline */
}

