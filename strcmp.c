#include "shell.h"
/**
 * _strcmp - to compare two strings.
 *
 * @strin1: first string.
 * @strin2: second string.
 *
 * Return: 0 if two string is same
 * -1 if string1 > string2
 * 1 if string1 < string2.
 */

int _strcmp(char *strin1, char *strin2)
{
	int i, strcm;

	strcm = 0;
	for (i = 0; (strin1[i] != '\0' || strin2[i] != '\0'); i++)
	{
		if (strin1[i] != strin2[i])
		{
			strcm = strin1[i] - strin2[i];
			if (strcm > 0)					/*compare char by char*/
				return (1);					/*if char > 0 return 1*/
			else							/*if char < 0 return -1*/
				return (-1);
		}
	}										
	return (0);								/*else return 0*/
}
