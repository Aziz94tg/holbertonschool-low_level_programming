#include "main.h"

/**
 * _strcmp - Compares two strings character by character.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: 0 if s1 == s2,
 *         Negative value if s1 < s2,
 *         Positive value if s1 > s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

