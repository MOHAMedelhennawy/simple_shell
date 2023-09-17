#include "shell.h"

/**
 * str_concat- concatenate 2 strings.
 * @s1: string 1.
 * @s2: string 2, concatenated to 1
 *
 * Return: pointer to the concatenated string.
 */
void concatenate_string(char* stringPart1, char* stringPart2)
{
	int lenStr1, i = 0;

	lenStr1 = _strlen(stringPart1);
    
    while (stringPart2[i] != '\0')
    {
        stringPart1[lenStr1 + i] = stringPart2[i];
        i++;
    }
    stringPart1[lenStr1 + i] = '\0';
}
