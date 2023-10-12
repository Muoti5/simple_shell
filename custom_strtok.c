#include "shell.h"
/**
 * _strtok - Function that tokenizes inout string
 * @input: pointer to input string being tokenized
 * @delimiters: pointer to string specifying delimiters
 * @tokens: pointer to array of char pointers
 * @num_tokens: pointer to integer that stores no of tokens
 *
 * Return: Void
 */
void _strtok(char *input, const char *delimiters,
		char **tokens, int *num_tokens)
{
int i;
char *token = strtok(input, delimiters);

if (input == NULL || delimiters == NULL || tokens == NULL || num_tokens == NULL)
{
return;
}
for (i = 0; i < MAX_TOKENS; i++)
{
tokens[i] = NULL;
}
*num_tokens = 0;

while (token != NULL)
{
if (*num_tokens >= MAX_TOKENS - 1)
{
fprintf(stderr, "Too many tokens\n");
exit (1);
}
tokens[(*num_tokens)++] = token;
token = strtok(NULL, delimiters);
}
}
