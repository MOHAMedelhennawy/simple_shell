#include "shell.h"
/**
 * _strcat - concatenate 2 strings.
 * @stringPart1: string 1.
 * @stringPart2: string 2, concatenated to 1
 *
 * Return: pointer to the concatenated string.
*/

void _strcat(char *stringPart1, char *stringPart2)
{
	int lenStr1, i = 0;

	lenStr1 = _strlen(stringPart1);				/*count number of digit*/

	while (stringPart2[i] != '\0')		/*check if curent char is equal to null terminated string*/
	{									/*if equal to null terminated break*/
		stringPart1[lenStr1 + i] = stringPart2[i];	/*put each char of string2*/
		i++;										/*at the end of string1*/
	}
	stringPart1[lenStr1 + i] = '\0';				/*Addin null terminated string in*/
}													/*the end of string1*/
