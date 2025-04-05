#include "function_pointers.h"
#include <stddef.h>
/**
 * print_name - calls a function that prints a name
 * @name: the name to print
 * @f: pointer to the printing function
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

