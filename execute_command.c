#include "shell.h"

/**
 * execute_child - This function executes a command in the child process
 * @command: pointer to command
 * @args: arguments
 *
 * Return: void
 */
void execute_child(char *command, char *args[])
{
	if (execve(command, args, environ) == -1)
	{
		execute_with_path(command, args);

		handle_error();
	}
}

/**
 * handle_error - This function handles errors and exit in the child process
 *
 * Return: void
 */
void handle_error(void)
{
	perror("</3 ");
	return;
}

/**
 * execute_command - This function executes a command
 *
 * @command : pointer to command input
 * Return: void
 */
void execute_command(char *command)
{
	char *args[256];
	int arg_count = 0;

	char *token = strtok(command, " \t\n");

	while (token != NULL && arg_count < 255)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		execute_with_path(args[0], args);
	}
}
