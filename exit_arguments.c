#include "shell.h"

int exit_with_arguments(char *bufff, char **oldBuf)
{
    int exit_status;
    char *word1, *word2;

    word1 = strtok(bufff, " ");
    if (_strcmp(word1, "exit") == 0)
        word2 = strtok(NULL, " ");
    else
    {
        free(bufff);
        return (1);
    }
    if (word2 != NULL)
        exit_status = _atoi(word2);

    free(bufff), free(*oldBuf);
    exit(exit_status);
    return (0);
}


/**
 * _atoi - Entery point
 *
 * @s: char pointer parameter.
 *
 * Description: convert a string to an integer.
 *
 * Return: always (0).
 */
int _atoi(char *stringNum)
{
	int pos_neg = 1, i = 0;
	unsigned int intNum = 0;

	do {
		if (stringNum[i] == '-')
			pos_neg *= -1;
    
		else if (stringNum[i] >= '0' && stringNum[i] <= '9')
			intNum = intNum * 10 + (stringNum[i] - '0');
    
		else if (intNum > 0)
			break;
	} while (stringNum[i++]);

	return (intNum * pos_neg);
}
