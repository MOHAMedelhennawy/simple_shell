#include "shell.h"

void print_number(int n)
{
	char c;

	if (n / 10)
		print_number(n / 10);
	c = (n % 10) + '0'; 
	write(STDOUT_FILENO , &c, 1);
}
