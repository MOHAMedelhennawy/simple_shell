#include "shell.h"

char *_strdup(char *string)
{
	int i, length_of_string = _strlen(string) + 1;
	char *newString;

	if (string == NULL)
		return (NULL);

	newString = malloc(sizeof(char) * length_of_string);
	if (newString == NULL)
		return (0);

	for (i = 0; i < length_of_string; i++)
		*(newString + i) = *(string + i);

	return (newString);
}
