#include "main.h"

/**
 * find_in_path - Searches for a command in the PATH directories
 * @command: The command name to search for (e.g. "ls")
 *
 * Return: Full path string if found (must be freed), NULL if not found
 */
char *find_in_path(char *command)
{
	char *path_env;
	char *path_copy;
	char *dir;
	char full_path[1024];
	struct stat st;

	/* If command already has a slash, use it directly */
	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	/* Get the PATH environment variable */
	path_env = getenv("PATH");
	if (path_env == NULL || path_env[0] == '\0')
		return (NULL);

	/* Duplicate because strtok modifies the string */
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	/* Walk through each directory in PATH */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
