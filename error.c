#include "shell.h"

/**
 * getline_error - check error
 *
 * @bytes: Number of bytes read or -1 in errorl
 * @ex: Exit status for error.
 * @comm: The full path of program.
 *
 * Description: This function check for getline error
 * and free the buff and exit if error exist.
 */
void getline_error(int bytes, size_t *ex, char *comm)
{
	if (bytes == -1)
	{
		if (isatty(STDIN_FILENO) != 0) /* Check for interactive move*/
			write(STDOUT_FILENO, "\n", 1);
		free(comm), exit(*ex);
	}
}
