#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for crackme5 given a username
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *username;
	char key[7];
	char *lookup = "A-CHRDw8H7lNS0E9BH2TibgpnMHVys5XzvtHOGJcYLU+H4mjW6fxqHZeF3Qa1rHPhdKIoukH";
	int len, i, sum, prod, max, r;

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* f1: (len ^ 0x3b) & 0x3f */
	key[0] = lookup[(len ^ 0x3b) & 0x3f];

	/* f2: (sum of chars ^ 0x4f) & 0x3f */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i];
	key[1] = lookup[(sum ^ 0x4f) & 0x3f];

	/* f3: (product of chars ^ 0x55) & 0x3f */
	prod = 1;
	for (i = 0; i < len; i++)
		prod *= username[i];
	key[2] = lookup[(prod ^ 0x55) & 0x3f];

	/* f4: (rand() from max char ^ 0xe) & 0x3f */
	max = username[0];
	for (i = 1; i < len; i++)
		if (username[i] > max)
			max = username[i];
	srand(max ^ 0xe);
	key[3] = lookup[rand() & 0x3f];

	/* f5: (sum of squares of chars ^ 0xef) & 0x3f */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i] * username[i];
	key[4] = lookup[(sum ^ 0xef) & 0x3f];

	/* f6: (rand() after looping username[0] times ^ 0xe5) & 0x3f */
	r = 0;
	for (i = 0; i < username[0]; i++)
		r = rand();
	key[5] = lookup[(r ^ 0xe5) & 0x3f];

	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}

