#include "shell.h"

/**
 * error_message - print error msg
 *
 * @Prog: The name of program.
 * @buff: The wrong command you insert.
 * @errNum: The number of line the error found.
 *
 * Description: This function print error msg
 * for wrong command insert by user.
 */
void error_message(char *Prog, char *buff, int errNum)
{   /* ./aout : 1 : sasklj : not found */
	write(STDERR_FILENO, Prog, _strlen(Prog)); /*//  ./aout*/
	write(STDERR_FILENO, ": ", 2);
	print_number(errNum); /* Print line number */
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buff, _strlen(buff));
	write(STDERR_FILENO, ": not found\n", 12);
}
