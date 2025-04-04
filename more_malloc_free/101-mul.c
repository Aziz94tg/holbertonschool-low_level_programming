#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int len1, len2, *res, i, j, n1, n2, carry;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 1; i <= 2; i++)
		for (j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (98);
			}

	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	res = calloc(len1 + len2, sizeof(int));
	if (!res)
		return (98);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = argv[1][i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			carry += res[i + j + 1] + (n1 * n2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		res[i + j + 1] += carry;
	}

	i = 0;
	while (i < len1 + len2 && res[i] == 0)
		i++;
	if (i == len1 + len2)
		printf("0");
	else
		for (; i < len1 + len2; i++)
			printf("%d", res[i]);
	printf("\n");

	free(res);
	return (0);
}

