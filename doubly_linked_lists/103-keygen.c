#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int f1(char *user) {
    int len = strlen(user);
    return (len ^ 0x3b) & 0x3f;
}

int f2(char *user) {
    int sum = 0;
    int i;
    for (i = 0; user[i]; i++)
        sum += user[i];
    return (sum ^ 0x4f) & 0x3f;
}

int f3(char *user) {
    int p = 1;
    int i;
    for (i = 0; user[i]; i++)
        p *= user[i];
    return (p ^ 0x55) & 0x3f;
}

int f4(char *user) {
    int max = user[0];
    int i;
    for (i = 1; user[i]; i++) {
        if (user[i] > max)
            max = user[i];
    }
    srand(max ^ 0xe);
    return rand() & 0x3f;
}

int f5(char *user) {
    int sum = 0;
    int i;
    for (i = 0; i < (int)user[0]; i++)
        sum += rand();
    return (sum ^ 0xef) & 0x3f;
}

int f6(char *user) {
    return ((user[0] ^ 0x11) + 0x1d) & 0x3f;
}

int main(int argc, char *argv[]) {
    char *user;
    char lookup[] = "A-CHRDw8H7lNS0E9BH2TibgpnMHVys5XzvtHOGJcYLU+H4mjW6fxqHZeF3Qa1rHPhdKIoukH";
    char key[7];

    if (argc != 2) {
        printf("Usage: %s username\n", argv[0]);
        return 1;
    }

    user = argv[1];

    key[0] = lookup[f1(user)];
    key[1] = lookup[f2(user)];
    key[2] = lookup[f3(user)];
    key[3] = lookup[f4(user)];
    key[4] = lookup[f5(user)];
    key[5] = lookup[f6(user)];
    key[6] = '\0';

    printf("%s\n", key);
    return 0;
}

