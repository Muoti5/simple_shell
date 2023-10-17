#include "shell.h"

/**
 * read_command - This function reads user input and parses the command.
 *
 * Return: user input
 */
char *read_command(void)
{
	char *line = '\0';

	line = my_getline();

	if (line == NULL)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
