#include "main.h"

/**
 * _strspn - gets length of matching letters at start of string
 * @s: the string to check
 * @accept: the letters we allow
 *
 * Return: number of letters in a row that match
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;
	unsigned int count = 0;
	int found;

	for (i = 0; s[i] != '\0'; i++) /* go through s */
	{
		found = 0;

		for (j = 0; accept[j] != '\0'; j++) /* check if s[i] is in accept */
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break; /* no need to keep checking */
			}
		}

		if (found == 0) /* if letter not in accept, stop counting */
			break;

		count++;
	}

	return (count);
}

