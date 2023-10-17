#include "shell.h"
/**
 * _strcat - This function concatenates two strings.
 *
 * @dest: String 1
 * @src: String 2
 *
 * Return: string dest
 */

char *_strcat(char *dest, char *src)
{
int j = 0, i;

while (dest[j])
{
j++;
}
for (i = 0; src[i] != 0; i++)
{
dest[j] = src[i];
j++;
}
dest[j] = '\0';
return (dest);
}
