#include "main.h"

/**
 * _strchr - find first time a letter shows up in a word
 * @s: the word
 * @c: the letter to look for
 *
 * Return: where the letter is, or NULL if not there
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0') /* go through the word */
	{
		if (*s == c)    /* if this letter is what we want */
			return (s); /* give back where it is */
		s++;            /* move to next letter */
	}

	if (c == '\0')      /* if we’re looking for the end of the word */
		return (s);     /* give back that spot */

	return (0);         /* if we didn’t find it */
}

