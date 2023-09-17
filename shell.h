#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
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

char *_getenv(const char *name);
d_node *build_linkedList(void);
int search_in_path(char *buf);
void free_list(d_node *head);

void getline_error(int bytes, char **buff);
void env_function();
void execuve_command_with_slash(char **bffer/*, char *programName, int n*/);

void error_message(char *argv, char *buff, int num);
void print_number(int n);

#endif