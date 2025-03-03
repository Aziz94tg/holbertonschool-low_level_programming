#include <stdio.h>

int main(void) {
    unsigned long a1 = 0, a2 = 1, b1 = 0, b2 = 2, next1, next2;
    int i;

    printf("%lu, %lu, %lu, %lu", a2, b2, a2 + b2, a2 + 2 * b2);

    for (i = 4; i < 98; i++) {
        next1 = a1 + b1;
        next2 = a2 + b2;
        if (next2 < a2 || (next2 == a2 && next1 < a1)) {
            next1++;
        }
        printf(", %lu", next2);
        a1 = b1;
        a2 = b2;
        b1 = next1;
        b2 = next2;
    }
    printf("\n");
    return 0;
}
