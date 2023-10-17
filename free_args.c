#include "shell.h"
/**
 * free_args - This function frees arguments.
 * @args: array of arguments
 *
 * Return: void
 */
void free_args(char *args[])
{
	int index;

	for (index = 0; args[index] != NULL; index++)
	{
		free(args[index]);
	}
	free(args);
}
