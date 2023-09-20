#include "shell.h"

/**
 * exit_with_arguments - exit status.
 *
 * @bufff: The buffer that have the entire command.
 * @oldBuf: To free it before exit from process.
 *
 * Description: This function exit from the current
 * process with exit status argument.
 *
 * Return: 1 in success and 0 in failer.
 */
int exit_with_arguments(char *bufff, char **oldBuf, char *programName)
{
	int exit_status;
	char *word1, *word2;

	word1 = _strtok(bufff, " "); /* Take the first word */
	if (_strcmp(word1, "exit") == 0) /* Check if it is exit or not */
		word2 = _strtok(NULL, " ");
	else
	{
		free(bufff); /* If the first word not exit */
		return (1); /* Free the bufff and return */
	}
	exit_status = _atoi(word2); /* convert the exit status from stirng to int */
	if (exit_status < 0)
	{
		perror("ds");
		return (0);
	}
	free(bufff), free(*oldBuf);
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

// void exit_neg()
// { /*sh: 1: exit: Illegal number: -98*/
// 	write(STDERR_FILENO, Prog, _strlen(Prog)); /*//  ./aout*/
// 	write(STDERR_FILENO, ": ", 2);
// 	print_number(errNum); /* Print line number */
// 	write(STDERR_FILENO, ": ", 2);
// 	write(STDERR_FILENO, buff, _strlen(buff));
// 	write(STDERR_FILENO, ": not found\n", 12);
// }
