#include "shell.h"
#define MAX_TOKENS 64
#define MAX_TOKEN_SIZE 64
/**
 * custom_strtok - Function that tokenizes inout string
 * @input: pointer to input string being tokenized
 * @delimiters: pointer to string specifying delimiters
 * @tokens: pointer to array of char pointers
 * @num_tokens: pointer to integer that stores no of tokens
 *
 * Return: Void
 */
void custom_strtok(char *input, const char *delimiters,
		char **tokens, int *num_tokens)
{
char *token = strtok(input, delimiters);
*num_tokens = 0;

while (token != NULL)
{
if (*num_tokens >= MAX_TOKENS - 1)
{
write(2, "Too many tokens", 15);
exit (1);
}
token[(*num_tokens)++] = token;
token = strtok(NULL, delimiters);
}
}
