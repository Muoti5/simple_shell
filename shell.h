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

extern char **environ;

char *read_command(void);
void execute_child(char *command, char *args[]);
void handle_error(void);
void execute_and_wait(char *command, char *args[]);
void execute_command(char *command);
void free_args(char *args[]);
char *my_getline();
void exit_command(char *args[], int arg_count, char *command);
void exit_shell(void);
void print_environment(void);
char *_getenv(const char *name);
void handle_exec_error(char* command);
char* construct_full_path(char* directory, char* command);
void execute_with_path(char* command, char *args[]);
char** create_exec_args(char* args[]);
void free_exec_args(char** exec_args);

#endif
