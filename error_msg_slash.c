#include "shell.h"

void error_message_permission_denied(char *argv, char *buff, int num)
{ /*// ./aout : 1 : sasklj : not found */
	write(STDERR_FILENO, argv, _strlen(argv)); /*//  ./aout*/
	write(STDERR_FILENO, ": ", 2); 
	print_number(num); 
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buff, _strlen(buff));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}
