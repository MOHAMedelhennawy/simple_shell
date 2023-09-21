#include "shell.h"
/**
 * print_number - to print the given number.
 * @n: the given number.
*/
void print_number(int n)
{
	char c;

	if (n / 10)
		print_number(n / 10);			/*print number using recursion*/
	c = (n % 10) + '0';
	write(STDERR_FILENO, &c, 1);
}
