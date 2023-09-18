#include "shell.h"

void getline_error(int bytes, char **buff, size_t *ex)
{
	if (bytes == -1)
	{
		if (isatty(STDIN_FILENO) != 0) /*;lkasdjf;klsadjf ;*/
			write(STDOUT_FILENO, "\n", 1);
		free(*buff), exit(*ex);
	}
}
