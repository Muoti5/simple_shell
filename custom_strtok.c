#include "shell.h"
/**
 * _strtok - Function that tokenizes inout string
 * @input: pointer to input string being tokenized
 * @delimiters: pointer to string specifying delimiters
 * @tokens: pointer to array of char pointers
 * @num_tokens: pointer to integer that stores no of tokens
 *
 * Return: Void
 */
char *custom_strtok(char *str, const char *delim, char **save_ptr) {
    char *token;

    if (str != NULL) {
        *save_ptr = str;
    }

    *save_ptr += strspn(*save_ptr, delim);

    if (**save_ptr == '\0') {
        return NULL;
    }

    token = *save_ptr;

    *save_ptr += strcspn(*save_ptr, delim);

    if (**save_ptr != '\0') {
        *(*save_ptr)++ = '\0';
    }

    return token;
}
