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
	if (execve(command, args, NULL) == -1)
	{
		perror("</3 ");
		exit(-1);
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
	exit(-1);
}

/**
 * execute_and_wait - executes a command and waits for the child process
 * @command: pointer to command
 * @args: array of arguments
 *
 * Return: void
 */
void execute_and_wait(char *command, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		execute_child(command, args);
	}
	else if (pid < 0)
	{
		handle_error();
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
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

	char *token = strtok(command, " \n");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \n");
	}
	args[arg_count] = NULL;

	execute_and_wait(args[0], args);
}
