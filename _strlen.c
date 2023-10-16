#include "shell.h"

/**
 * _strlen - This function calculates the length of a null-terminated string
 * @str: String
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	const char *s = str;

	while (*s)
	{
		s++;
	}

	return (s - str);
}
