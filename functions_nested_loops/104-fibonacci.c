#include <stdio.h>

int main(void) {
    unsigned long a = 1, b = 2, next;
    unsigned long a_high = 0, b_high = 0, next_high;
    int i;

    printf("%lu, %lu", a, b);

    for (i = 2; i < 98; i++) {
        next = a + b;
        next_high = a_high + b_high;

        if (next < a) {
            next_high++;
        }

        printf(", %lu", next);

        a_high = b_high;
        a = b;
        b_high = next_high;
        b = next;
    }

    printf("\n");
    return 0;
}
