#include "shell.h"

/**
 * handle_exec_error - This function handles errors for execve function
 *
 * @command: command to be executed
 * Return: void
 */
void handle_exec_error(char *command)
{
	perror(command);
	return;
}

/**
 * construct_full_path - This function constructs the full path by
 * concatenating directory and command
 *
 * @directory: directory
 * @command: command
 * Return: full path
 */
char *construct_full_path(char *directory, char *command)
{
	char *full_path;
	
	char *input = strdup(command);

	if (input == NULL)
	{
		return (NULL);
	}

	if (strchr(command, '/') != NULL)
	{
		return (input);
	}
	
	full_path= malloc(strlen(directory) + strlen(command) + 2);
	if (full_path == NULL)
	{
		free(input);
		return (NULL);
	}

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, command);

	free(input);
	return (full_path);
}

/**
 * execute_with_path - This function attempts to execute a command by searching
 * for it in the directories listed in the PATH environment variable 
 * @command: command
 * @args: arguments
 * Return: void
 */

void execute_with_path(char *command, char *args[])
{
	char *path = _getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char *full_path = construct_full_path(token, command);
		printf("Constructed path: %s\n", full_path);

		if (access(full_path, X_OK) == 0)
		{
			char **exec_args = create_exec_args(args);
			
			execute_and_wait(full_path, exec_args);
			free_exec_args(exec_args);
			free(full_path);
			return;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	handle_exec_error(command);
}
