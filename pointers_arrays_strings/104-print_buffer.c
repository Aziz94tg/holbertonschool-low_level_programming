#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints the content of a buffer.
 * @b: Buffer (array of bytes).
 * @size: Number of bytes to print.
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
            printf((offset + byte < size) ? "%02x%s" : "   ", b[offset + byte], (byte % 2) ? " " : "");

        for (byte = 0; byte < 10 && offset + byte < size; byte++)
            printf("%c", (b[offset + byte] >= 32 && b[offset + byte] <= 126) ? b[offset + byte] : '.');

        printf("\n");
    }
}

