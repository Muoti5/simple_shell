#include "shell.h"

/**
 * execute_and_wait - This function forks processes
 * @command: command
 * @args: arguments
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
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				handle_error();
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
