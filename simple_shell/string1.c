#include "shell.h"

/**
 * _strcpy - This copies a string.
 * @dest: This is the destination.
 * @src: This is the source.
 *
 * Return: This returns pointer to destination.
 *
 */
char *_strcpy(char *dest, char *src)
{
	int ice = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[ice])
	{
		dest[ice] = src[ice];
		ice++;
	}
	dest[ice] = 0;
	return (dest);
}

/**
 * _strdup - This duplicates a string.
 * @str: This is the string to duplicate.
 *
 * Return: This returns a pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts -This prints an input string.
 *@str: This is the string to be printed.
 *
 * Return: The return is Nothing.
 */
void _puts(char *str)
{
	int ice = 0;

	if (!str)
		return;
	while (str[ice] != '\0')
	{
		_putchar(str[ice]);
		ice++;
	}
}

/**
 * _putchar - This writes the character c to the stdout.
 * @c: This is the character to print.
 * Return: This will return 1 On success.
 * -1 is returned on error, and errno is set appropriately.
 */
int _putchar(char car)
{
	static int ice;
	static char buf[WRITE_BUF_SIZE];

	if (car == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, ice);
		ice = 0;
	}
	if (car != BUF_FLUSH)
		buf[ice++] = car;
	return (1);
}

