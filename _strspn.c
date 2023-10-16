#include "shell.h"

/**
 * _strspn - This function iterates through the input string and counts the
 * number of characters at the beginning of the string present in specified set
 * of characters
 *
 * @str: String
 * @set: character set to be searched for in the input string
 * Return: count
 */
size_t _strspn(const char *str, const char *set)
{
	int found;
	size_t count = 0;

	while (*str)
	{
		const char *ch;
		found = 0;

		for (ch = set; *ch; ch++)
		{
			if (*str == *ch)
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			break;
		}
		str++;
		count++;
	}

	return (count);
}
