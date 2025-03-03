#include "main.h"

/**
 * jack_bauer - Prints every minute of the day from 00:00 to 23:59
 */
void jack_bauer(void)
{
    int hour, min;

    for (hour = 0; hour < 24; hour++)  /* Loop through hours */
    {
        for (min = 0; min < 60; min++)  /* Loop through minutes */
        {
            _putchar('0' + (hour / 10));  /* Print tens digit of hour */
            _putchar('0' + (hour % 10));  /* Print ones digit of hour */
            _putchar(':');                /* Print ':' */
            _putchar('0' + (min / 10));   /* Print tens digit of minute */
            _putchar('0' + (min % 10));   /* Print ones digit of minute */
            _putchar('\n');               /* Print newline */
        }
    }
}
