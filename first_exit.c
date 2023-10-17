#include "shell.h"

/**
 * first_exit_shell - This function handles the exit built-in command.
 *
 * Return: void.
 */
void first_exit_shell(void)
{
	const char *exit_message = "exit\n\n[Disconnected...]\n";

	write(1, exit_message, strlen(exit_message));
	exit(0);
}
