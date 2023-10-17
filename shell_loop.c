#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * Return: 0 indicating success
 */
int main(void)
{
if (isatty(STDIN_FILENO))
{
InteractiveShell();
}
else
{
NonInteractiveShell();
}
return (0);
}
/**
 * InteractiveShell - Function that runs on interactive mode
 *
 * Return: Void
 */
void InteractiveShell(void)
{
char *read_line = NULL;
char prompt[] = "$ ";

do {
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
read_line = read_command();

if (read_line == NULL)
{
write(STDOUT_FILENO, "exit\n\n[Disconnected...]\n", 24);
break;
}
if (strcmp(read_line, "exit\n") == 0)
{
first_exit_shell();
}
else if (strcmp(read_line, "env\n") == 0)
{
print_environment();
}
else if (strlen(read_line) > 1)
{
execute_command(read_line);
}
free(read_line);
} while (1);
}
/**
 * NonInteractiveShell - Function runs on non interactive mode
 *
 * Return: void
 */
void NonInteractiveShell(void)
{
char *read_line = NULL;
do {
read_line = read_command();
if (read_line == NULL)
{
break;
}
else if (strcmp(read_line, "exit\n") == 0)
{
first_exit_shell();
}
else if (strcmp(read_line, "env\n") == 0)
{
print_environment();
}
else if (strlen(read_line) > 1)
{
execute_command(read_line);
}
free(read_line);
} while (1);
}
