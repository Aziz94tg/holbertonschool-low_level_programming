#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates and prints a valid key for the crackme5 program
 */
int main(int argc, char *argv[])
{
	char *username = argv[1];
	char key[7];
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37,
		0x4d6e706762695432, 0x74767a5835737956,
		0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850
	};

	int i, len = strlen(username), sum = 0, prod = 1, max = username[0], sum_sq = 0;

	if (argc != 2)
		return (1);

	key[0] = (len ^ 59) & 63;
	key[1] = (username[0] ^ 79) & 63;
	for (i = 0; i < len; i++)
	{
		sum += username[i];
		prod *= username[i];
		if (username[i] > max)
			max = username[i];
		sum_sq += username[i] * username[i];
	}
	key[2] = (sum ^ 239) & 63;
	key[3] = (prod ^ 229) & 63;
	srand(max ^ 14);
	key[4] = rand() & 63;
	key[5] = (sum_sq ^ 239) & 63;

	for (i = 0; i < 6; i++)
		printf("%c", (int)alph[(int)key[i]]);
	putchar('\n');
	return (0);
}

