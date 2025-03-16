#include "main.h"

/**
 * _strncat - Concatenates two strings, using at most n bytes from src
 * @dest: The destination string (where src will be appended)
 * @src: The source string to append to dest
 * @n: The max number of bytes to copy from src
 *
 * Return: Pointer to dest (the modified string)
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_len = 0; /* Keep track of the length of dest */
    int i = 0; /* Counter for src */

    /* Find the end of dest (where null terminator is) */
    while (dest[dest_len] != '\0')
    {
        dest_len++;
    }

    /* Copy up to n characters from src to dest */
    while (i < n && src[i] != '\0')
    {
        dest[dest_len] = src[i];
        dest_len++;
        i++;
    }

    /* Make sure dest is null-terminated */
    dest[dest_len] = '\0';

    return dest;
}

