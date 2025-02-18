#include "main.h"

/**
 * _isalpha - Checks if a character is an alphabetic letter.
 * @c: The character to check.
 *
 * Description: This function checks if the given character `c`
 * is either an uppercase ('A' - 'Z') or a lowercase ('a' - 'z') letter.
 * If it is an alphabetic character, it returns 1; otherwise, it returns 0.
 *
 * Return: 1 if `c` is a letter, 0 otherwise.
 */


int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
