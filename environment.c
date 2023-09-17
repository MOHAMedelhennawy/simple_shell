#include "shell.h"

void env_function()
{
	int j = 0;

	while (environ[j] != NULL) 
	{
		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
		write (STDOUT_FILENO, "\n", 1);
		j++;
	}
}
