#include <stdio.h>

int f1(int input) {
    return (input ^ 0x3b) & 0x3f;
}

int main() {
    for (int i = 0; i < 128; i++) {
        printf("f1(%d) = %d\n", i, f1(i));
    }
    return 0;
}

