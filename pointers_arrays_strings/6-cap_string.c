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
	int capitalize_next = 1; /* Flag: 1 = capitalize next letter */

	/* Characters that separate words */
	char separators[] = " \t\n,;.!?\"(){}";

	/* Loop through each character */
	while (s[i] != '\0')
	{
		/* Capitalize letter if needed */
		if (capitalize_next && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - ('a' - 'A'); /* Convert to uppercase */
		}

		/* Reset flag after checking a character */
		capitalize_next = 0;

		/* Check if current character is a separator */
		for (int j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j])
			{
				capitalize_next = 1; /* Next character should be capitalized */
				break;
			}
		}

		i++; /* Move to the next character */
	}

	return (s);
}

