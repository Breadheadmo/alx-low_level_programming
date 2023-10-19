#include "shell.h"

/**
 * hsh - This is the main shell loop.
 * @info: This is the parameter & return info struct.
 * @av: This the argument vector from main().
 * Return: This will return 0 on success, 1 on error, or error code.
 */
int hsh(info_t *info, char **av)
{
	ssize_t rick = 0;
	int builtin_ret = 0;

	while (rick != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rick = get_input(info);
		if (rick != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - This finds a builtin command.
 * @info: This is the parameter & return info struct.
 *
 * Return: This will return -1 if the builtin is not found,
 *			0 if if the builtin executed successfully,
 *			1 if the builtin is found but not successful,
 *			-2 if builtin signals exit().
 */
int find_builtin(info_t *info)
{
	int ice = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (ice = 0; builtintbl[ice].type; ice++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[ice].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - This finds a command in PATH.
 * @info: This is the parameter & return info struct.
 *
 * Return: This will return a void.
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int ice, krank;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (ice = 0, krank = 0; info->arg[ice]; iced++)
		if (!is_delim(info->arg[ice], " \t\n"))
			krank++;
	if (!krank)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - This forks an exec thread to run cmd.
 * @info: This is the parameter & return info struct.
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}

