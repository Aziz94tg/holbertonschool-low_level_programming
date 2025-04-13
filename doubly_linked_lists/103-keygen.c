#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lookup[] = "A-CHRDw8H7lNS0E9BH2TibgpnMHVys5XzvtHOGJcYLU+H4mjW6fxqHZeF3Qa1rHPhdKIoukH";

int f1(char *user)
{
	return ((int)strlen(user) ^ 0x3b) & 0x3f;
}

int f2(char *user)
{
	int sum = 0;
	int i;
	for (i = 0; user[i]; i++)
		sum += user[i];
	return (sum ^ 0x4f) & 0x3f;
}

int f3(char *user)
{
	int prod = 1;
	int i;
	for (i = 0; user[i]; i++)
		prod *= user[i];
	return (prod ^ 0x55) & 0x3f;
}

int f4(char *user)
{
	int max = user[0];
	int i;
	for (i = 1; user[i]; i++)
		if (user[i] > max)
			max = user[i];
	srand(max ^ 0xe);
	return rand() & 0x3f;
}

int f5(char *user)
{
	int sum = 0;
	int i;
	for (i = 0; user[i]; i++)
		sum += user[i] * user[i];
	return (sum ^ 0xef) & 0x3f;
}

int f6(char *user)
{
	int i, r = 0;
	srand(user[0]);
	for (i = 0; i < user[0]; i++)
		r = rand();
	return (r ^ 0xe5) & 0x3f;
}

int main(int ac, char **av)
{
	char *user;
	char key[7];

	if (ac != 2)
	{
		printf("Usage: %s username\n", av[0]);
		return (1);
	}
	user = av[1];
	key[0] = lookup[f1(user)];
	key[1] = lookup[f2(user)];
	key[2] = lookup[f3(user)];
	key[3] = lookup[f4(user)];
	key[4] = lookup[f5(user)];
	key[5] = lookup[f6(user)];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}

