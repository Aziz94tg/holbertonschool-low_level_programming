#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - chooses the correct math operation
 * @s: the operator
 *
 * Return: pointer to matching function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (*s == *(ops[i].op) && !s[1])
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

