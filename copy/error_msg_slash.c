#include "shell.h"

/**
 * error_message_permission_denied - print error msg
 *
 * @Prog: The name of program.
 * @buff: The wrong command you insert.
 * @errNum: The number of line the error found.
 *
 * Description: This function print the error message
 * "Permission denied" when user insert wrong path
 * for command like "/bin/" or "///" or "./"
 */
void error_message_permission_denied(char *Prog, char *buff, int errNum)
{    /* ./hsh: 1: sasklj: not found */
	write(STDERR_FILENO, Prog, _strlen(Prog));
	write(STDERR_FILENO, ": ", 2);
	print_number(errNum); /* Print line number */
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buff, _strlen(buff));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}
