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
		if (access(command, F_OK | X_OK) == 0)
			execute_and_wait(command, args);
		else
			handle_error();
	}
	else
	{
		char *path = strdup(_getenv("PATH"));
		char *token = strtok(path, ":");
		int found = 0;

		while (token != NULL)
		{
			char *full_path = malloc(_strlen(token) + _strlen(command) + 2);

			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (access(full_path, F_OK | X_OK) == 0)
			{
				execute_and_wait(full_path, args);
				found = 1;
				free(full_path);
				break;
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
		if (!found)
			handle_error();
	}
}
