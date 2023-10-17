#include "shell.h"
/**
 * _strspn - This function gets the length of a prefix substring.
 *
 * @s: String 1
 * @accept: String 2
 *
 * Return: No. of bytes in string s in string accept
 */
unsigned int _strspn(char *s, const char *accept)
{
	int a, b, c;

	a = 0;
	c = 0;

	while (s[a] != '\0')
	{
		b = 0;
		while (accept[b] != '\0')
		{
			if (s[a] == accept[b])
			{
				c++;
				break;
			}
			b++;
		}
		if (accept[b] == '\0')
			break;
		a++;
	}
	return (c);
}
