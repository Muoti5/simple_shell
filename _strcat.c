#include "shell.h"

/**
 * _strcat - Concatenates dset string to the source string
 * @dest: Destination string
 * @src: Source string
 * Return: Concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
