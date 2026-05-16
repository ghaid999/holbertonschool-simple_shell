#include "main.h"

/**
 * execute_command - Executes a command using execve
 * @args: Array of command and its arguments
 *
 * Return: Nothing
 */
 
void execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t chars_read;
	char *args[64];
	char *token;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			fflush(stdout);
		}

		chars_read = getline(&line, &line_size, stdin);

		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");

			free(line);
			exit(0);
		}

		i = 0;
		token = strtok(line, " \t\n");

		while (token != NULL && i < 63)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \t\n");
		}

		args[i] = NULL;

		if (args[0] == NULL)
			continue;

		execute_command(args);
	}

	free(line);
	return (0);
}
