#include "shell.h"

/**
 * _strlen - This function calculates the length of a null-terminated string
 * @s: String
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int d;

	d = 0;

	while (*s != '\0')
	{
		d++;
		s++;
	}

	return (d);
}
