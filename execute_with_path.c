#include "shell.h"

/**
 * execute_with_path - This function executes commands using PATH
 * @command: args[0]
 * @args: arguments
 * Return: void
 */
void execute_with_path(char *command, char *args[])
{
	if (command[0] == '/')
	{
		execute_and_wait(command, args);
	}
	else
	{
		char *path = _getenv("PATH");
		 char *token = strtok(path, ":");

		while (token != NULL)
		{
			char *full_path = malloc(strlen(token) + strlen(command) + 2);

			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command);
			if (access(full_path, X_OK) == 0)
			{
				execute_and_wait(full_path, args);
				free(full_path);
				return;
			}	
			free(full_path);
			token = strtok(NULL, ":");
		}		
		handle_error();
	}
}
