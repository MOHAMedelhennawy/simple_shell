#include "shell.h"
#include <string.h>

/**
 * main - the main function to execute our own shell.
 * @argc: number of arguments.
 * @argv: the passed arguments to program.
 * Return: return
 */
int main(int __attribute__ ((unused)) argc, char *argv[])
{
	size_t len = 0, num = 1, ex = EXIT_SUCCESS, itr = 0;
	int st;
	char *buff[] = {NULL}, *allComm = NULL;
	ssize_t readBytes;

	while ('T')
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		readBytes = getline(&allComm, &len, stdin);
			getline_error(readBytes, &ex, allComm);
		buff[0] = strtok(allComm, " ");
		if (strcmp(buff[0], "\n") == 0)
		{
			num++;
			continue;
		}
		allComm[readBytes - 1] = '\0', itr = 0;
		while (buff[itr++] != NULL) /* splits the command to strings */
			buff[itr] = strtok(NULL, " ");

		if (_strcmp(buff[0], "env") == 0)			/*if buff equal to env go to function*/
			env_function();							/*and print all enviroment varuable*/
		if (_strcmp(buff[0], "exit") == 0 && !buff[1])
			free(allComm), exit(ex); /*if buff equal to exit go to function and exit*/
		st = exit_with_arguments(buff);	/*to execute the commands*/
		if (st == -1)
		{
			exit_negative_error(argv[0], buff[1], buff[0], num), ex = 2;
			continue;
		}
		if (access(buff[0], F_OK) == 0)
			ex = execuve_command_with_slash(buff, argv[0], num);
		else if (_strcmp(buff[0], "env") && search_in_path(buff) == 127)
			error_message(argv[0], buff[0], num), ex = 127;
		else
			ex = 0;
		num++;
	}
	return (0);
}
