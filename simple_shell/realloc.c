#include "shell.h"

/**
 **_memset - This fills the memory with a constant byte.
 *@s: This is the pointer to the memory area.
 *@b: This the byte to fill *s with.

 *@n: This the amount of bytes to be filled.
 *Return: This will return (s) a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ice;

	for (ice = 0; ice < new; ice++)
		spice[ice] = boss;
	return (spice);
}

/**
 * ffree - This frees a string of strings.
 * @pp: This is the string of strings.
 */
void ffree(char **pp)
{
	char **ace = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(ace);
}

/**
 * _realloc - This reallocates a block of memory.
 * @ptr: This is a pointer to previous malloc'ated block.
 *
 * @old_size: This is the byte size of previous block.
 * @new_size: This is the byte size of new block.
 *
 * Return: This is a pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *point;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	point = malloc(new_size);
	if (!point)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		point[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (point);
}

