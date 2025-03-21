#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings.
 * @n1: First number as a string.
 * @n2: Second number as a string.
 * @r: Buffer to store the result.
 * @size_r: Size of the buffer.
 *
 * Return: Pointer to the result, or 0 if it can't be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, sum, carry = 0, index = size_r - 2;

	while (n1[i] != '\0')
		i++; /* Find length of n1 */
	while (n2[j] != '\0')
		j++; /* Find length of n2 */

	r[size_r - 1] = '\0'; /* Null-terminate the result */

	while (i > 0 || j > 0 || carry) /* Add digits from right to left */
	{
		if (index < 0)
			return (0); /* Buffer overflow */

		sum = carry;
		if (i > 0)
			sum += n1[--i] - '0';
		if (j > 0)
			sum += n2[--j] - '0';

		r[index] = (sum % 10) + '0'; /* Store last digit */
		index--;
		carry = sum / 10; /* Carry for next iteration */
	}

	return (r + index + 1); /* Return pointer to result */
}
