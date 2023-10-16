#include "shell.h"
#define MAX_LINE_LENGTH 1024
char *my_getline();
static char buffer[MAX_LINE_LENGTH];
static size_t buf_position;
static size_t buff_size;
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
char *newline = NULL;
char *newbuf = NULL;

while (true)
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
newline = malloc(buf_position);
if (newline == NULL)
{
perror("memory allocation");
exit(EXIT_FAILURE);
}
memcpy(newline, buffer, buf_position);
newline[buf_position - 1] = '\0';
free(line);
line = newline;
return (line);
}
}
newbuf = malloc(length + buff_size + 1);
if (newbuf == NULL)
{
perror("memory allocation");
exit(EXIT_FAILURE);
}
memcpy(newbuf + length, buffer, buff_size);
free(line);
line = newbuf;
length += buff_size;
buf_position = buff_size;
}
}
