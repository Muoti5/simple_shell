#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

char *read_command(void);
void execute_child(char *command, char *args[]);
void handle_error(void);
void execute_and_wait(char *command, char *args[]);
void execute_command(char *command);
void free_args(char *args[]);
char *my_getline();
void exit_command(char *args[], int arg_count, char *command);
void _strtok(char *input, const char *delimiters, char **tokens, int *num_tokens);
#endif
