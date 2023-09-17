#include "shell.h"

void getline_error(int bytes, char **buff)
{
	if (bytes == -1)
	{
		if (isatty(STDIN_FILENO) != 0) /*;lkasdjf;klsadjf ;*/
			write(STDOUT_FILENO, "\n", 1);
		free(*buff), exit(EXIT_FAILURE);
	}
}
