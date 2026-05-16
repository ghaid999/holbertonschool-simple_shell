#include "main.h"

/**
 * main - simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	size_t len;
	ssize_t nread;
	pid_t pid;
	int status;
	char *args[2];

	line = NULL;
	len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			exit(0);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args[0] = line;
		args[1] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(line);
			exit(1);
		}

		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
