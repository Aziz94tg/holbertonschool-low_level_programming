#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: input string
 * Return: number of words
 */
int count_words(char *str)
{
	int i = 0, wc = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			wc++;
		i++;
	}
	return (wc);
}

/**
 * word_len - length of a word starting at str[i]
 * @str: input string
 * @i: start index
 * Return: length of word
 */
int word_len(char *str, int i)
{
	int len = 0;

	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * strtow - splits a string into words
 * @str: input string
 * Return: pointer to array of words or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k = 0, start, len, wc;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = count_words(str);
	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (str[i] && k < wc)
	{
		while (str[i] == ' ')
			i++;
		start = i;
		len = word_len(str, i);
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
		i += len;
		k++;
	}
	words[k] = NULL;
	return (words);
}

