#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: pointer to an array of 8 chars
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++) /* go through each row */
	{
		for (j = 0; j < 8; j++) /* go through each column in row */
		{
			_putchar(a[i][j]); /* print the piece or space */
		}
		_putchar('\n'); /* go to next line after each row */
	}
}

