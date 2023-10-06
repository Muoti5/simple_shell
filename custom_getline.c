#include "shell.h"
#define MAX_LINE_LENGTH 1024
static char buffer[MAX_LINE_LENGTH];
static size_t buf_position = 0;
static size_t buff_size = 0;
/*
 * my_getline- function that reads a line of text from STDI
 *
 * Return: A pointer to the read line, or NULL on end-of-file or error.
 */
char *my_getline()
{
ssize_t x;
ssize_t length = 0;
char *line = NULL;

while(true)
{
if (buf_position >= buff_size)
{
x = read(STDIN_FILENO, buffer, MAX_LINE_LENGTH);
if (x < 0)
{
perror("input data");
exit(EXIT_FAILURE);
}
if (x == 0)
{
return (NULL);
}
buff_size = x;
buf_position = 0;
}
for (; buf_position < buff_size; ++buf_position)
{
if (buffer[buf_position] == '\n')
{
++buf_position;
line = malloc(length + buf_position + 1);
if (line == NULL)
{
perror("memory allocation");
exit(EXIT_FAILURE);
}
memcpy(line + length, buffer, buf_position);
length += buf_position;
line[length] = '\0';
return (line);
}
}
line = malloc(length + buff_size + 1);
if (line == NULL)
{
perror("memory allocation");
exit(EXIT_FAILURE);
}
memcpy(line + length, buffer, buff_size);
length += buff_size;
buf_position = buff_size;
free(line);
return (line);
}
}
