#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    if (n / 10)
        print_number(n / 10);

    _putchar((n % 10) + '0');
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int count;
    int fib1 = 1, fib2 = 2, fib_next;

    print_number(fib1);
    _putchar(',');
    _putchar(' ');

    print_number(fib2);
    _putchar(',');
    _putchar(' ');

    for (count = 3; count <= 98; count++)
    {
        fib_next = fib1 + fib2;
        print_number(fib_next);

        if (count != 98)
        {
            _putchar(',');
            _putchar(' ');
        }

        fib1 = fib2;
        fib2 = fib_next;
    }

    _putchar('\n');

    return (0);
}
