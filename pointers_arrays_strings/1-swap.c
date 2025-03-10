#include "main.h"

/**
 * swap_int - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_int(int *a, int *b)
{
    int temp; /* Temporary variable to hold one value */

    temp = *a; /* Save the value of 'a' */
    *a = *b;   /* Assign 'b' to 'a' */
    *b = temp; /* Assign saved value to 'b' */
}

