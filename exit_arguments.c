#include "shell.h"

/**
 * exit_with_arguments - exit status.
 *
 * @bufff: The buffer that have the entire command.
 *
 * Description: This function exit from the current
 * process with exit status argument.
 *
 * Return: 1 in success and 0 in failer.
 */
int exit_with_arguments(char **bufff)
{
	int exit_status;

	if (_strcmp(bufff[0], "exit") != 0) /* Check if it is exit or not */
	{
		return (1); /* Free the bufff and return */
	}
	exit_status = _atoi(bufff[1]); /* convert the exit status from stirng to int*/
	if (exit_status < 0)
	{
		return (0);
		free(bufff[0]), free(bufff[1]);
	}
	free(bufff[0]);
	exit(exit_status);
	return (0);
}


/**
 * _atoi - string to integar
 *
 * @stringNum: The string you want to convert it to int.
 *
 * Description: This function convert the given string
 * to integar number to use it in exit status.
 *
 * Return: The converted number with sign.
 */
int _atoi(char *stringNum)
{
	int pos_neg = 1, i = 0;
	unsigned int intNum = 0;

	do {
		if (stringNum[i] == '-') /* Check for first char in string */
			pos_neg = -1; /* make the sign in negative */

		else if (stringNum[i] >= '0' && stringNum[i] <= '9')
			intNum = intNum * 10 + (stringNum[i] - '0'); /* Convert to integar */

		else if (intNum > 0)
			break; /* IF the previous else if fail and the intNm has a value*/
	} while (stringNum[i++]);

	return (intNum * pos_neg); /* Number * (- or +) */
}
