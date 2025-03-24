#include "main.h"

/**
 * _strpbrk - finds the first letter in s that’s also in accept
 * @s: the string to look in
 * @accept: the letters to search for
 *
 * Return: pointer to where the match happens, or NULL if no match
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)  /* go through s */
	{
		for (j = 0; accept[j] != '\0'; j++)  /* check each letter in accept */
		{
			if (s[i] == accept[j])  /* if there's a match */
				return (&s[i]);     /* return pointer to the match */
		}
	}

	return (0);  /* if no match is found */
}

