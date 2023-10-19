#include "shell.h"

/**
 * is_chain - This will test if current char in buffer is a chain delimeter.
 * @info: This is the parameter struct.
 * @buf: This is the char buffer.
 * @p: This is the address of the current position in buf.
 *
 * Return: This returns 1 if chain delimeter, 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *point)
{
	size_t juice = *point;

	if (buf[juice] == '|' && buf[juice+ 1] == '|')
	{
		buf[juice] = 0;
		juice++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[juice] == '&' && buf[juice + 1] == '&')
	{
		buf[juice] = 0;
		juice++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[juice] == ';') /* found end of this command */
	{
		buf[juice] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*point = juice;
	return (1);
}

/**
 * check_chain - This checks we should continue chaining based on last status.
 * @info: This is the parameter struct.
 * @buf: This is the char buffer.
 * @p: This is the address of current position in buf.
 * @i: This is the starting position in buf.
 * @len: This is the length of buf.
 *
 * Return: This returns a Void.
 */
void check_chain(info_t *info, char *buf, size_t *point, size_t ice, size_t len)
{
	size_t juice = *point;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[ice] = 0;
			juice = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[ice] = 0;
			juice = len;
		}
	}

	*point = juice;
}

/**
 * replace_alias - This replaces an aliases in the tokenized string.
 * @info: This is the parameter struct.
 *
 * Return: This returns 1 if replaced, 0 otherwise.
 */
int replace_alias(info_t *info)
{
	int ice;
	list_t *node;
	char *point;

	for (ice = 0; ice < 10; ice++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		point = _strchr(node->str, '=');
		if (!point)
			return (0);
		point = _strdup(point + 1);
		if (!point)
			return (0);
		info->argv[0] = point;
	}
	return (1);
}

/**
 * replace_vars - This replaces the vars in the tokenized string.
 * @info: This is the parameter struct.
 *
 * Return: This returns 1 if replaced, 0 otherwise.
 */
int replace_vars(info_t *info)
{
	int ice = 0;
	list_t *node;

	for (ice = 0; info->argv[ice]; ice++)
	{
		if (info->argv[ice][0] != '$' || !info->argv[ice][1])
			continue;

		if (!_strcmp(info->argv[ice], "$?"))
		{
			replace_string(&(info->argv[ice]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[ice], "$$"))
		{
			replace_string(&(info->argv[ice]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[ice][1], '=');
		if (node)
		{
			replace_string(&(info->argv[ice]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - This replaces the string.
 * @old: This is the address of the old string.
 * @new: This is a new string.
 *
 * Return: This returns 1 if replaced, 0 otherwise.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

