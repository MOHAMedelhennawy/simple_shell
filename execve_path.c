#include "shell.h"

void execuve_command_with_slash(char **bffer/*, char *programName, int n*/)
{
	int i = 0;

	if (fork() == 0)
		{
			while (bffer[i++] != NULL)
				bffer[i] = strtok(NULL, " ");
			execve(bffer[0], bffer, NULL);
				/*error_message(programName, bffer[0], n);*/ 
			free(bffer[0]);
			exit(EXIT_SUCCESS);
			
		}
		wait(NULL);
}
