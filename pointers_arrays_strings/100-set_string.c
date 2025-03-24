#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to a pointer to a char (we want to change this)
 * @to: string to point to
 */
void set_string(char **s, char *to)
{
	*s = to;
}

