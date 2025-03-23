#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: the byte to fill the memory with
 * @n: the number of bytes to fill
 *
 * Return: pointer to the memory area (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	/* loop through the memory area and set each byte to the value of b */
	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	/* return the original pointer */
	return (s);
}
                                                                                        
~                                                                     
