#include "shell.h"
/**
 * custom_strtok - Function that tokenizes inout string
 * @str: pointer to input string being tokenized
 * @delim: pointer to string specifying delimiters
 * @save_ptr: pointer to pointer char input
 *
 * Return: tokenized characters
 */
char *custom_strtok(char *str, const char *delim, char **save_ptr)
{
char *token;

if (str != NULL)
{
*save_ptr = str;
}
*save_ptr += _strspn(*save_ptr, delim);
if (**save_ptr == '\0')
{
return (NULL);
}
token = *save_ptr;
*save_ptr += _strcspn(*save_ptr, delim);
if (**save_ptr != '\0')
{
*(*save_ptr)++ = '\0';
}
return (token);
}
