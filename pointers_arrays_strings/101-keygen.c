#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random password for 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int sum = 0;
    int target = 2772; /* We assume this is the required sum */
    char password[100];
    int i = 0;
    int random_char;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Keep adding characters until we are close to the target */
    while (sum < target - 126) /* 126 is max printable ASCII value */
    {
        random_char = (rand() % 94) + 33; /* Printable ASCII (33 to 126) */
        password[i] = random_char;
        sum += random_char;
        i++;
    }

    /* Adjust the last character to match the exact sum */
    password[i] = target - sum;
    password[i + 1] = '\0'; /* Null terminate the string */

    /* Print the final password */
    printf("%s\n", password);

    return (0);
}

