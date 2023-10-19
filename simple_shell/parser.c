#include "shell.h"

/**
 * is_cmd - This determines if a file is an executable command.
 * @info: The info structure.
 * @path: This a path to the file.
 *
 * Return: This returns 1 if true, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - This duplicates characters.
 * @pathstr: This is the PATH string.
 * @start: This is the starting index.
 * @stop: The is for stopping the index.
 *
 * Return: This returns pointer to new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int ice = 0, krank = 0;

	for (krank = 0, ice = start; ice < stop; ice++)
		if (pathstr[ice] != ':')
			buf[krank++] = pathstr[ice];
	buf[krank] = 0;
	return (buf);
}

/**
 * find_path - This finds this cmd in the PATH string.
 * @info: The info structure.
 * @pathstr: This is the PATH string.
 *
 * @cmd:This is the cmd to find.
 *
 * Return: This will return full path of cmd if found or NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int ice = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[ice] || pathstr[ice] == ':')
		{
			path = dup_chars(pathstr, curr_pos, ice);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[ice])
				break;
			curr_pos = ice;
		}
		ice++;
	}
	return (NULL);
}

