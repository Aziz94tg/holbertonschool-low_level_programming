#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @s: The input string to encode.
 *
 * Return: Pointer to the modified string.
 */
char *rot13(char *s)
{
    int i, j;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[] =    "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    /* Loop through the input string */
    for (i = 0; s[i] != '\0'; i++)
    {
        /* Loop through the alphabet array to find a match */
        for (j = 0; alphabet[j] != '\0'; j++)
        {
            if (s[i] == alphabet[j]) /* If character is found in alphabet */
            {
                s[i] = rot13[j]; /* Replace with corresponding ROT13 letter */
                break; /* Stop searching once replaced */
            }
        }
    }

    return (s); /* Return pointer to modified string */
}                                                                                                                                               
