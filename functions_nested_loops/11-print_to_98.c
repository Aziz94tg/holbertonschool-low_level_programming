#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: Starting number
 */
void print_to_98(int n)
{
    if (n <= 98) /* Count up to 98 */
    {
        for (; n <= 98; n++)
        {
            printf("%d", n);
            if (n != 98) /* Print comma and space if not last number */
                printf(", ");
        }
    }
    else /* Count down to 98 */
    {
        for (; n >= 98; n--)
        {
            printf("%d", n);
            if (n != 98) /* Print comma and space if not last number */
                printf(", ");
        }
    }
    printf("\n"); /* Print newline at the end */
}
