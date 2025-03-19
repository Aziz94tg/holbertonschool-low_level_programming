#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer in hex and ASCII format.
 * @b: The buffer (array of bytes).
 * @size: The number of bytes to print.
 */
void print_buffer(char *b, int size)
{
	int offset, byte;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);

		for (byte = 0; byte < 10; byte++)
		{
			if (offset + byte < size)
				printf("%02x", b[offset + byte]);
			else
				printf("  ");

			if (byte % 2 == 1)
				printf(" ");
		}

		for (byte = 0; byte < 10 && offset + byte < size; byte++)
		{
			if (b[offset + byte] >= 32 && b[offset + byte] <= 126)
				printf("%c", b[offset + byte]);
			else
				printf(".");
		}

		printf("\n");
	}
}

