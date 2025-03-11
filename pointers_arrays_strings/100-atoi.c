#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer safely.
 * @s: The input string.
 *
 * Return: The integer value from the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int found_digit = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			/* Prevent overflow before it happens */
			if (num > (INT_MAX / 10) ||
			    (num == (INT_MAX / 10) && (s[i] - '0') > (INT_MAX % 10)))
			{
				if (sign == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}
			num = (num * 10) + (s[i] - '0');
			found_digit = 1;
		}
		else if (found_digit)
			break;

		i++;
	}

	return (num * sign);
}

