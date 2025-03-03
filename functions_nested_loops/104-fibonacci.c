#include <stdio.h>

/**
 * print_fibonacci_normal - Prints Fibonacci numbers from 1 to 90
 * @a: First number
 * @b: Second number
 */
void print_fibonacci_normal(unsigned long int a, unsigned long int b)
{
    unsigned long int next;
    int count;

    printf("%lu, %lu", a, b);  /* Print first two Fibonacci numbers */

    for (count = 3; count <= 90; count++)  /* Loop from 3rd to 90th Fibonacci */
    {
        next = a + b;  /* Compute next Fibonacci number */
        printf(", %lu", next);
        a = b;  /* Move forward */
        b = next;
    }
}

/**
 * print_fibonacci_large - Prints Fibonacci numbers from 91 to 98
 * @a: First large number
 * @b: Second large number
 */
void print_fibonacci_large(unsigned long int a, unsigned long int b)
{
    unsigned long int a_high, a_low, b_high, b_low, next_high, next_low;
    int count;

    /* Start from correct F(89) and F(90) */
    a_high = a / 1000000000;
    a_low = a % 1000000000;
    b_high = b / 1000000000;
    b_low = b % 1000000000;

    for (count = 91; count <= 98; count++)
    {
        next_high = a_high + b_high;  /* Add high parts */
        next_low = a_low + b_low;  /* Add low parts */

        if (next_low >= 1000000000)  /* Handle overflow in low part */
        {
            next_high += 1;
            next_low -= 1000000000;
        }

        /* ✅ Correct printing format (no leading zeros) */
        printf(", %lu%09lu", next_high, next_low);

        /* Update values for next Fibonacci number */
        a_high = b_high;
        a_low = b_low;
        b_high = next_high;
        b_low = next_low;
    }
}

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    unsigned long int a = 1, b = 2;

    print_fibonacci_normal(a, b); /* Print first 90 Fibonacci numbers */
    print_fibonacci_large(2880067194370816120, 4660046610375530309);  /* Print last 8 Fibonacci numbers */

    printf("\n");
    return (0);
}

