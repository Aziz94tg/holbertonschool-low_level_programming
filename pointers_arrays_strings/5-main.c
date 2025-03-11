#include "main.h"
#include <stdio.h>

/**
 * main - Tests the rev_string function
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[10] = "My School";

    printf("%s\n", s); /* Print original string */
    rev_string(s);     /* Reverse the string */
    printf("%s\n", s); /* Print reversed string */

    return (0);
}

