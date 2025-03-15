#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * 
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0; /* Index for dest */
    int j = 0; /* Index for src */

    /* Find the end of the dest string */
    while (dest[i] != '\0')
    {
        i++;
    }

    /* Append src to dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Add the terminating null byte */
    dest[i] = '\0';

    return dest;
}

