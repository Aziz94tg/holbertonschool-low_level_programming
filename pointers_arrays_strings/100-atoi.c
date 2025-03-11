#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value from the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int found_digit = 0;

	while (s[i] != '\0') /* Go through the string */
	{
		/* If we find a minus sign, flip the sign */
		if (s[i] == '-')
			sign *= -1;
		/* If we find a plus sign, do nothing (just keep moving) */
		else if (s[i] == '+')
			sign *= 1;
		/* If we find a digit, start building the number */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num = (num * 10) + (s[i] - '0');
			found_digit = 1; /* Mark that we've found a number */
		}
		/* If we've already started forming a number and hit a non-digit, stop */
		else if (found_digit)
			break;

		i++;
	}

	/* Multiply by sign to get the correct positive/negative number */
	return (num * sign);
}

