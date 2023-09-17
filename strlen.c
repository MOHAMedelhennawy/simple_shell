#include "shell.h"
/**
 * _strlen - Entery point
 *
 * @s: char parameter.
 *
 * Description: returns the length of a string.
 *
 * Return: Always 0.
 */
int _strlen(char *string)
{
	int itrat = 0;

	while (string[itrat] != '\0')
		itrat++;

	return (itrat);
}
