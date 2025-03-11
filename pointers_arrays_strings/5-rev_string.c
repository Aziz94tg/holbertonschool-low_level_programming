#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: Pointer to the string
 */
void rev_string(char *s)
{
	int len = 0, i;
	char temp;

	/* Step 1: Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Step 2: Swap characters from the ends moving towards the middle */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i]; /* Store left-side character */
		s[i] = s[len - 1 - i]; /* Swap with right-side character */
		s[len - 1 - i] = temp; /* Store temp back to the right-side */
	}
}

