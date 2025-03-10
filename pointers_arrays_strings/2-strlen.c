#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
    int len = 0; /* Counter to store length */

    while (s[len] != '\0') /* Loop until the null terminator */
    {
        len++; /* Increment the counter */
    }
    return (len);
}
