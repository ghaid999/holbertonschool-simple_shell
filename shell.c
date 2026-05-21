#include "main.h"

/**
 * execute_command - Executes a command using execve
 * @args: Array of command and its arguments
 *
 * Return: Nothing
 */
void execute_command(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;
	char *cmd_path;

	cmd_path = find_in_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		return;
	}


	
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			free(cmd_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(cmd_path);
}

/**
 * read_input - Reads a line from standard input
 * @line: Buffer that stores the input
 * @line_size: Size of the input buffer
 *
 * Return: 1 on success, 0 on EOF
 */
int read_input(char **line, size_t *line_size)
{
	ssize_t chars_read;

	chars_read = getline(line, line_size, stdin);

	if (chars_read == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");

		return (0);
	}

	return (1);
}

/**
 * parse_arguments - Splits the command line into arguments
 * @line: Input line entered by the user
 * @args: Array to store command and arguments
 *
 * Return: Nothing
 */
void parse_arguments(char *line, char **args)
{
	char *token;
	int i = 0;
	int len;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

	token = strtok(line, " \t\n");

	while (token != NULL && i < 63)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}

	args[i] = NULL;
}

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t line_size = 0;
	char *args[64];
	(void)argc; 

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			fflush(stdout);
		}

		if (read_input(&line, &line_size) == 0)
		{
			free(line);
			exit(0);
		}

		parse_arguments(line, args);

		if (args[0] == NULL)
			continue;

		execute_command(args, argv[0]);
	}

	free(line);
	return (0);
}
