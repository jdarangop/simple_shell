#ifndef _SHELL_H_
#define _SHELL_H_

/* Required libraries */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* Environmental variables */
extern char **environ;

/* Function declarations (prototypes) for main functions*/
void _loop(void);
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args);
int _launch(char **args);

/* Function declarations (prototypes for for builtin shell commands */
int hsh_exit(void);
int _cd(char **args);
int _help(void);
/* int _env(char **args); */

/* Function declarations (prototypes) for auxiliary funtions */
ssize_t _getline(char **b, size_t *bufsize, FILE *stream);
int _getc(void);

char *_strtok(char *s, const char *delim);
char *_strtok_r(char *s, const char *delim, char **save_str);
int _strcspn(char *s, const char *delim);
int _strspn(char *s, const char *delim);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getenv(const char *name);
char **_path(char *path);
char **_split_path(char *line, char *copy_line);
char **_check_path(char **args, int *flag);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
void _puts(char *str);


#endif
