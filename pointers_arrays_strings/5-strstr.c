char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')  /* if needle is empty, return haystack */
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)  /* go through haystack */
	{
		for (j = 0; needle[j] != '\0'; j++)  /* go through needle */
		{
			if (haystack[i + j] != needle[j])
				break;
		}

		if (needle[j] == '\0')  /* if we matched all of needle */
			return (&haystack[i]);  /* return where it started */
	}

	return (0);  /* if needle was not found */
}
