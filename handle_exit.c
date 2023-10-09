#include "shell.h"
/**
 * exit_command - Function that handles the exit command
 * @args: array of string input
 * @arg_count: integer inpout
 *
 * Return: Nothing
 */
void exit_command(char *args[], int arg_count, char *command)
{
int status;
const char *error_message;

/**printf("exit_command called with arg_count: %d\n", arg_count); **/
if (arg_count == 1)
{
free(command);
exit(0);
}
else if (arg_count == 2)
{
status = atoi(args[1]);
free(command);
exit(status);
}
else
{
error_message = "Usage: exit [status]\n";
write(STDERR_FILENO, error_message, strlen(error_message));
free(command);
}
}
