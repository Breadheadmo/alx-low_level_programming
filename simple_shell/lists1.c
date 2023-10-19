#include "shell.h"

/**
 * list_len - This will determine the length of a linked list.
 * @h: This is a pointer to the first node.
 * Return: This returns the size of a list.
 */
size_t list_len(const list_t *horror)
{
	size_t ice = 0;

	while (horror)
	{
		horror = horror->next;
		ice++;
	}
	return (ice);
}

/**
 * list_to_strings - This will return an array of strings of the list->str.
 * @head: This points to the first node.
 *
 * Return: The return will be an array of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t ice = list_len(head), juice;
	char **strs;
	char *str;

	if (!head || !ice)
		return (NULL);
	strs = malloc(sizeof(char *) * (ice + 1));
	if (!strs)
		return (NULL);
	for (ice = 0; node; node = node->next, ice++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (juice = 0; juice < ice; juice++)
				free(strs[juice]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[ice] = str;
	}
	strs[ice] = NULL;
	return (strs);
}


/**
 * print_list - This prints all the contents of a list_t linked list.
 * @h: This points to the first node.
 *
 * Return: This returns the size of a list.
 */
size_t print_list(const list_t *horror)
{
	size_t ice = 0;

	while (horror)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(horror->str ? horror->str : "(nil)");
		_puts("\n");
		horror = horror->next;
		ice++;
	}
	return (ice);
}

/**
 * node_starts_with - This will returns the node whose string starts with a prefix.
 * @node: This is a pointer to lists head.
 * @prefix: This is a string to match.
 * @c: This will be the next character after prefix to match.
 *
 * Return: This will match the node or it will return null.
 */
list_t *node_starts_with(list_t *node, char *prefix, char car)
{
	char *point = NULL;

	while (node)
	{
		point = starts_with(node->str, prefix);
		if (point && ((car == -1) || (*point == car)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - This will get the index of a node.
 * @head: This points to lists head.
 * @node: This points to the node.
 *
 * Return: This will return the index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t ice = 0;

	while (head)
	{
		if (head == node)
			return (ice);
		head = head->next;
		ice++;
	}
	return (-1);
}

