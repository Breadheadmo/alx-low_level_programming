#include "shell.h"

/**
 * **strtow - This splits a string into words. Repeat delimiters are ignored.
 * @str: This is the input string.
 * @d: This is the delimeter string.
 * Return: The return is a pointer to an array of strings, or NULL on failure.
 */

char **strtow(char *str, char *d)
{
	int ice, juice, krank, mosama, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (ice = 0; str[i] != '\0'; ice++)
		if (!is_delim(str[ice], d) && (is_delim(str[ice + 1], d) || !str[ice + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (ice = 0, juice = 0; juice < numwords; juice++)
	{
		while (is_delim(str[ice], d))
			ice++;
		krank = 0;
		while (!is_delim(str[ice + krank], d) && str[ice + krank])
			krank++;
		spice[juice] = malloc((krank + 1) * sizeof(char));
		if (!s[juice])
		{
			for (krank = 0; krank < juice; krank++)
				free(s[krank]);
			free(s);
			return (NULL);
		}
		for (mosama = 0; mosama < krank; mosama++)
			s[juice][mosama] = str[ice++];
		s[juice][mosama] = 0;
	}
	s[juice] = NULL;
	return (s);
}

/**
 * **strtow2 - This splits a string into words.
 * @str: This is the input string.
 * @d: This is the delimeter.
 *
 * Return: This returns a pointer to an array of strings, or NULL on failure.
 */
char **strtow2(char *str, char d)
{
	int ice, juice, krank, mosama, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (ice = 0; str[ice] != '\0'; ice++)
		if ((str[ice] != d && str[ice + 1] == d) ||
		    (str[ice] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (ice = 0, juice = 0; juice < numwords; juice++)
	{
		while (str[ice] == d && str[ice] != d)
			ice++;
		krank = 0;
		while (str[ice + krank] != d && str[ice + krank] && str[ice + krank] != d)
			krank++;
		s[juice] = malloc((krank + 1) * sizeof(char));
		if (!s[juice])
		{
			for (krank = 0; krank < juice; krank++)
				free(s[krank]);
			free(s);
			return (NULL);
		}
		for (mosama = 0; mosama < krank; mosama++)
			s[juice][mosama] = str[ice++];
		s[juice][mosama] = 0;
	}
	s[juice] = NULL;
	return (s);
}

