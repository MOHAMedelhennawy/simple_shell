#include "shell.h"

/**
 * exit_negative_error - print error msg
 *
 * @nameP: The name of program.
 * @neg: The wrong command you insert.
 * @errNum: The number of line the error found.
 * @exitName: Name of exit (exit).
 * Description: This function print error msg
 * for wrong command insert by user.
 */
void exit_negative_error(char *nameP, char *neg, char *exitName, int errNum)
{   /* ./aout : 1 : sasklj : not found */
	write(STDERR_FILENO, nameP, _strlen(nameP)); /*//  ./aout*/
	write(STDERR_FILENO, ": ", 2);
	print_number(errNum); /* Print line number */
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, exitName, _strlen(exitName));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, neg, _strlen(neg));
	write(STDERR_FILENO, "\n", 1);
}
