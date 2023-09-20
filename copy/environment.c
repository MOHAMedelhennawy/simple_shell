#include "shell.h"

/**
 * env_function - print environ
 *
 * Description: This function print all the environment
 * varilable from the environ global varibale with
 * write system call.
 */
void env_function(void)
{
	int envNum = 0;

	while (environ[envNum] != NULL)
	{
		write(STDOUT_FILENO, environ[envNum], _strlen(environ[envNum]));
		write(STDOUT_FILENO, "\n", 1); /* Make new line after print each env */
		envNum++; /* Move to next evnironment */
	}
}
