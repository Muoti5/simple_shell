#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 indicating success
 */
int main(void)
{
	char *read_line = NULL;
	char prompt[] = "$ ";
	
	do {
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		read_line = read_command();

		if (read_line == NULL)
		{
			write(STDOUT_FILENO, "\n\ndisconnected...\n", 18);
			break;
		}

		if (strlen(read_line) > 1)
		{
			execute_command(read_line);
		}
		else if (strcmp(read_line, "env\n") == 0)
		{
			print_environment();
		}
		
		free(read_line);
	} while (1);
	
	return (0);
}
