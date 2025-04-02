#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * @str: the string
 * Return: pointer to array of words or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, start, wc = 0, len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			wc++;
		i++;
	}

	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = k = 0;
	while (str[i] && k < wc)
	{
		while (str[i] == ' ')
			i++;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		len = i - start;
		words[k] = malloc((len + 1) * sizeof(char));
		if (words[k] == NULL)
		{
			while (k > 0)
				free(words[--k]);
			free(words);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			words[k][j] = str[start + j];
		words[k][j] = '\0';
		k++;
	}
	words[k] = NULL;
	return (words);
}

