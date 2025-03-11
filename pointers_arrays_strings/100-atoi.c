#include "main.h"
#include <limits.h> /* For INT_MAX and INT_MIN */

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

    while (s[i] != '\0') /* Loop through the string */
    {
        if (s[i] == '-')  /* If '-' is found, flip the sign */
            sign *= -1;
        else if (s[i] >= '0' && s[i] <= '9') /* If a digit is found */
        {
            /* Check if multiplying by 10 or adding a new digit will cause overflow */
            if (num > (INT_MAX / 10) || (num == (INT_MAX / 10) && (s[i] - '0') > (INT_MAX % 10)))
            {
                /* If overflow happens, return the max or min int */
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            num = (num * 10) + (s[i] - '0'); /* Convert character to number */
            found_digit = 1; /* Mark that a number has started */
        }
        else if (found_digit) /* Stop when a non-digit appears after a number */
            break;

        i++;
    }

    return (num * sign);
}

