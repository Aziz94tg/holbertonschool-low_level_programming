#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @s: The string to encode
 *
 * Return: Pointer to the modified string
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char leet_chars[] = "4433007711";

	/* Loop through each character in the string */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Loop through the list of letters to check for a match */
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j]) /* If the character matches, replace it */
			{
				s[i] = leet_chars[j];
				break; /* Stop checking once we replace the character */
			}
		}
	}

	return (s);
}

