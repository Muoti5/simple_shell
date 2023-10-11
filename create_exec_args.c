#include "shell.h"

/**
 * create_exec_args - This function handles the dynamic allocation and copying
 * of command-line arguments
 *
 * @args: array of arguments
 * Return: exec_args
 */
char **create_exec_args(char *args[])
{
	char **exec_args;

	int count = 0;
	int i = 0;
	
	while (args[count] != NULL)
	{
		count++;
	}

	exec_args = malloc((count + 1) * sizeof(char*));

	for (i = 0; i < count; ++i)
	{
		exec_args[i] = strdup(args[i]);
	}

	exec_args[count] = NULL;

	return (exec_args);
}

/**
 * free_exec_args - This function is used to free the allocated memory for
 * arguments after the execve call
 *
 * @exec_args: arguments
 * Return: void
 */
void free_exec_args(char **exec_args)
{
	int i = 0;

	for (i = 0; exec_args[i] != NULL; ++i)
	{
		free(exec_args[i]);
	}
	free(exec_args);
}
