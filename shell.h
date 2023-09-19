#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>

extern char **environ;

typedef struct dirNode 
{
    char *directory;
    struct dirNode *nextDir;
}d_node;

char *_getenv(char *name);
d_node *build_linkedList(void);
int search_in_path(char *buf);
void free_list(d_node *head);

void getline_error(int bytes, char **buff, size_t *ex);
void env_function(void);
int execuve_command_with_slash(char **bffer, char *programName, int n, char **pathbuf);

void error_message(char *argv, char *buff, int num);
void error_message_permission_denied(char *argv, char *buff, int num);

void print_number(int n);
int exit_with_arguments(char *bufff, char **oldBuf);
int _atoi(char *s);

void _strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
void _strcat(char* s, char* s1);
int _strcmp(char *strin1, char *strin2);
int check_node_for_execuve(d_node **head, char **buffer);
char *_strtok(char *str, char *delim);

#endif
