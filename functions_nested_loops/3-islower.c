#include "main.h"

/** _islower(int c) - Returns 1 if c is lowercase, 0 otherwise
 *
 * Description: checks for lowercase character
 *
 * Return: Always 0
 */


int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
