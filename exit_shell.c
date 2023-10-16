#include "shell.h"
/**
 * exit_shell - Function that handles the exit command
 * @args: array of string input
 * @arg_count: integer inpout
 * @command: pointer to char input
 *
 * Return: Nothing
 */
void exit_shell(char *args[], char *command)
{
int status;
const char *exit_message = "exit\n\n[Disconnected...]\n";

if (args[1] == 0)
{
free(command);
exit(0);
}
else if (args[1] != NULL)
{
status = atoi(args[1]);
free(command);
exit(status);
}
else
{
write(STDOUT_FILENO, exit_message, strlen(exit_message));
free(command);
}
}
