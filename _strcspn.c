#include "shell.h"

/**
 * _strcspn - This function calculates the length of the initial segment of a
 * string that consists of characters not in another string
 * @str: Input string
 * @reject: String containing characters to exclude from initial length calc
 * Return: the length
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *ptr1 = str;
	const char *ptr2 = reject;
	size_t count = 0;

	while (*ptr1 != '\0')
	{
		while (*ptr2 != '\0')
		{
			if (*ptr1 == *ptr2)
			{
				return (count);
			}
			++ptr2;
		}
		++ptr1;
		++count;
	}

	return (count);
}
