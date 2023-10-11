#include "shell.h"
/**
 * read_command - Function that accepyts user input
 *
 * Return: void
 */
char *read_command(void)
{
char *line = my_getline();

if (line == NULL)
{
return (NULL);
}
	ssize_t read_size = getline(&line, &bufsize, stdin);

	if (read_size == -1)
	{
		free(line);
		return (NULL);
	}

return (line);
}
