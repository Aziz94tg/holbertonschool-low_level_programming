#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with FizzBuzz replacements
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0) /* Multiple of both 3 and 5 */
            printf("FizzBuzz");
        else if (i % 3 == 0) /* Multiple of 3 */
            printf("Fizz");
        else if (i % 5 == 0) /* Multiple of 5 */
            printf("Buzz");
        else
            printf("%d", i); /* Print the number */

        if (i < 100)
            printf(" "); /* Print a space between numbers */
    }

    printf("\n"); /* Print a newline at the end */
    return (0);
}
