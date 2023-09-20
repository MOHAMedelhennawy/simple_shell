#include "shell.h"

/**
 * execuve_command_with_slash - excute process
 *
 * @bffer: The buffer that have the full command .
 * @programName: The name of program for error msg.
 * @n:Number of line for error msg.
 * @pathbuf: Free path buffer when finish the process.
 *
 * Description: This function excute the command inserted by user like
 * /bin/ls command or /bin/ls -l -h /tmp.
 *
 * Return: 0 always success.
 */
int execuve_command_with_slash(char **bffer, char *programName, int n,
char **pathbuf)
{
	int itr = 0, status;

	if (fork() == 0) /* Check for child process */
	{
		while (bffer[itr++] != NULL) /* splits the command to strings */
			bffer[itr] = _strtok(NULL, " ");
		if (execve(bffer[0], bffer, environ) == -1)
			error_message_permission_denied(programName, *bffer, n);

		free(bffer[0]), free(*pathbuf);
		exit(EXIT_SUCCESS); /* Exit with 0 status */
	}
	wait(&status); /* Make the parent process wait for child process terminate */
	return (WEXITSTATUS(status));
}
