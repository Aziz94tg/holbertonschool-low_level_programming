#include "main.h"

/**
 * _islower - Returns 1 if c is lowercase, 0 otherwise
 *@c: the character to check
 * Description: checks for lowercase character
 *
 * Return: Always 0
 */


int _islower(int c)
	/* checks for lowercase character */
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
