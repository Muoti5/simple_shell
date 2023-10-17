#include "shell.h"

/**
 * _getenv - This function takes a string pointer 'name' and returns a pointer
 * to a character representing the value of the environment variable.
 *
 * @name: string pointer representing the environment variable name
 *
 * Return: Pointer to a character representing the value of the environment var
 */
char *_getenv(const char *name)
{
	int name_length = _strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)
				[name_length] == '=')
		{
			return (*env + name_length + 1);
		}

		env++;
	}
	return (NULL);
}
