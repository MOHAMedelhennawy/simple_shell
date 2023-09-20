#include "shell.h"
/**
 * _strdup - to copy the given string to new string
 * stored in heap
 *
 * @string: origin string.
 *
 * Return: the copied string
 */
char *_strdup(char *string)
{
	int i, length_of_string = _strlen(string) + 1;
	char *newString;

	if (string == NULL)				 /*return NULL if no string there*/
		return (NULL);

	newString = malloc(sizeof(char) * length_of_string);	/*store in heap*/
	if (newString == NULL)
		return (0);

	for (i = 0; i < length_of_string; i++)
		*(newString + i) = *(string + i);		/*put each char in new string*/

	return (newString);
}
