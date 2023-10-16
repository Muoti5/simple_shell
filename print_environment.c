#include "shell.h"

/**
 * print_environment - This function handles the env built-in command
 *
 * Return: void
 */
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}
