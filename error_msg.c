#include "shell.h"

void error_message(char *argv, char *buff, int num)
{ /*// ./aout : 1 : sasklj : not found */
	write(STDERR_FILENO, argv, strlen(argv)); /*//  ./aout*/
	write(STDERR_FILENO, ": ", 2); 
	print_number(num); 
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buff, strlen(buff));
	write(STDERR_FILENO, ": not found\n", 12);
}
