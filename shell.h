#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/wait.h>

extern char **environ;

char *read_command(void);
void execute_child(char *command, char *args[]);
void handle_error(void);
void execute_command(char *command);
void free_args(char *args[]);
void print_environment(void);
void exit_shell(char *args[], char *command);
char *_getenv(const char *name);
char *custom_strtok(char *str, const char *delim, char **save_ptr);
char *my_getline();
void execute_with_path(char* command, char *args[]);
void execute_and_wait(char *command, char *args[]);

#endif
