#include "shell.h"

/**
 * _strlen - This returns the length of a string.
 * @s: This is the string whose length to check.
 *
 * Return: 
 * integer: The length of a string.
 */
int _strlen(char *spice)
{
	int ice = 0;

	if (!spice)
		return (0);

	while (*spice++)
		ice++;
	return (ice);
}

/**
 * _strcmp - This performs lexicogarphic comparison of two strangs.
 * @s1: This is the first string.
 * @s2: This is the second string.
 *
 * Return: This will return negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - This will check if needle starts with haystack.
 * @haystack: This is the string to search.
 *
 * @needle: This is the substring to find.
 *
 * Return: This will return address of next char of haystack or NULL.
 */
char *starts_with(const char *heystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - This concatenates two strings.
 * @dest: This is the destination buffer.
 * @src: This is the source buffer.
 *
 * Return: This will return a pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

