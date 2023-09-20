#include "shell.h"
/**
 * _strlen - to count number of digit of given string
 * @string: origin string.
 * Return: Number of digit.
 */
int _strlen(char *string)
{
	int itrat = 0;

	while (string[itrat] != '\0')
		itrat++;					/*count until reach to end of string*/

	return (itrat);					/*return number of digit*/
}
