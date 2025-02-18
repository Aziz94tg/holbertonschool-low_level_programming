#include "main.h"

 /**
 *  _isalpha - Checks if a character is an alphabetic letter.
 * @c: char to check
 *
 * Description: checks if c is alphabetic character
 *
 * Return: 1 if c is a letter, lowercase or uppercase, 0 otherwise
 */


int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
