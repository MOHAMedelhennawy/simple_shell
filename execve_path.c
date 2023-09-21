#include "shell.h"

/**
 * execuve_command_with_slash - excute process
 *
 * @bffer: The buffer that have the full command .
 * @programName: The name of program for error msg.
 * @n:Number of line for error msg.
 *
 * Description: This function excute the command inserted by user like
 * /bin/ls command or /bin/ls -l -h /tmp.
 *
 * Return: 0 always success.
 */
int execuve_command_with_slash(char **bffer, char *programName, int n)
{
	int status;

	if (fork() == 0) /* Check for child process */
	{
		if (execve(bffer[0], bffer, environ) == -1)
			error_message(programName, *bffer, n);

		free(bffer[0]);
		exit(EXIT_SUCCESS); /* Exit with 0 status */
	}
	wait(&status); /* Make the parent process wait for child process terminate */
	return (WEXITSTATUS(status));
}
