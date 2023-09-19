#include "shell.h"

int execuve_command_with_slash(char **bffer, char *programName, int n, char **pathbuf, char **exitbuf)
{
	int i = 0;

	if (fork() == 0)
	{
		while (bffer[i++] != NULL)
			bffer[i] = _strtok(NULL, " ");
		if (execve(bffer[0], bffer, NULL) == -1)
				error_message_permission_denied(programName, *bffer, n);

		free(bffer[0]), free(*pathbuf);
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	return (EXIT_SUCCESS);
}
