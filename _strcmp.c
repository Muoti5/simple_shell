#include "shell.h"

/**
 * _strcmp - This function iterates through input strings and compares them
 * @str1: String 1
 * @str2: String 2
 * Return: integer
 */
int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
