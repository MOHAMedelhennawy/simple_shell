#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

extern char **environ;

/**
 * struct dirNode - build linked list
 *
 * @directory: The directory in PATH environment varibale
 * @nextDir: Points to the next node
 *
 * Description: This struct for build a new linked list
 * to use it in storing PATH directories.
 */
typedef struct dirNode
{
	char *directory;
	struct dirNode *nextDir;
} d_node;


void getline_error(int bytes, char **buff, size_t *ex);
void env_function(void);
int execuve_command_with_slash(char **bffer, char *programName);

char *_getenv(char *name);
d_node *build_linkedList(void);
void free_list(d_node *head);
int search_in_path(char **buf);
int check_node_for_execuve(d_node **head, char **buffer);


void error_message(char *argv, char *buff, int num);
void error_message_permission_denied(char *argv, char *buff, int num);
void print_number(int n);
int exit_with_arguments(char **bufff);
int _atoi(char *s);

void _strcpy(char *firstString, char *secondString);
char *_strdup(char *string);
int _strlen(char *string);
void _strcat(char *stringPart1, char *stringPart2);
int _strcmp(char *strin1, char *strin2);

char *_strtok(char *strin, char *delim);

#endif
