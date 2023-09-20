#include "shell.h"
/**
 * _strcpy - to copy the given string to new string
 *
 * @firstString: string that copied to.
 *
 * @secondString: origin string that will copied.
 */
void _strcpy(char *firstString, char *secondString)
{
	int length = 0, i;

	while (secondString[length] != '\0')
		length++; /*count number of digit of origin string */

	for (i = 0; i <= length; i++)
		firstString[i] = secondString[i];	 /*put second string in first one*/
}
