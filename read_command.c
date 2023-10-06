#include "shell.h"

/**
 * read_command - This function reads user input and parses the command.
 *
 * Return: user input
 */
char *read_command(void)
{
	char *line = '\0';
	size_t bufsize = 0;

	ssize_t read_size = getline(&line, &bufsize, stdin);

	if (read_size == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
