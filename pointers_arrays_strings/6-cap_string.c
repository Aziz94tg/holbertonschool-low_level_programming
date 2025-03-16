#include "main.h"

/**
 * cap_string - Capitalizes the first letter of every word in a string
 * @s: The string to modify
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;
	int capitalize_next = 1; /* 1 = capitalize next letter */
	int j; /* Declare variable */

	/* Characters that separate words */
	char separators[] = " \t\n,;.!?\"(){}";

	/* Loop through each character */
	while (s[i] != '\0')
	{
		/* Capitalize if needed */
		if (capitalize_next && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - ('a' - 'A'); /* Convert to uppercase */
		}

		/* Reset flag */
		capitalize_next = 0;

		/* Check for word separators */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j])
			{
				capitalize_next = 1;
				break;
			}
		}

		i++; /* Move to the next character */
	}

	return (s);
}

