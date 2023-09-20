#include "shell.h"
/**
 * _strtok - splitting a string by some delimiter
 *
 * @strin: a string to splitting
 * @delim: the given delimter
 *
 * Return: It returns the pointer to the first token encountered in the string.
 * or returns NULL if there are no more tokens found.
 */
char *_strtok(char *strin, char *delim)
{
	static char *each_char;
	char *word;

	/*to intialize each_char if is NULL && in strin is not equal NULL*/
	if (strin != NULL)
		each_char = strin;

	/*if each_char is NULL or reach to end of string*/
	if (!each_char || *each_char == '\0')
		return (NULL);

	/*to Re-point to the next word*/
	word = each_char;
	while (*each_char != '\0')			  /*if reach to end of string break*/
	{
		if (*each_char == *delim)
		{
			*each_char = '\0';		 /*check char by char if is equl*/
			each_char++;			 /*to delim re-place it with '\0*/
			return (word);			 /*and return the word*/
		}
		each_char++;
	}
	return (word);
}
