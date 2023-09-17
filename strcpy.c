#include "shell.h"

void _strcpy(char *firstString, char *secondString)
{
	int length = 0, i;

	while (secondString[length] != '\0')
		length++;

	for (i = 0; i <= length; i++)
		firstString[i] = secondString[i];
}
