#include "shell.h"

/**
 * _strncmp - compares two strings character by character up to a given limit
 * @str1: String 1
 * @str2: String 2
 * @n: maximum number of characters to compare
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		
		str1++;
		str2++;
		n--;
	}
	
	return (0);
}
