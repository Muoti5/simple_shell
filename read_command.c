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

return (line);
}
