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
	size_t len = 0, num = 1, ex = EXIT_SUCCESS, i = 0;
	char *entireCommand, *buff[] = {NULL};
	ssize_t readBytes;

	while ('T')
	{
		i = 0;
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		readBytes = getline(&entireCommand, &len, stdin); /* "ls    -l -h  /tmp"*/
			getline_error(readBytes, &buff[0], &ex); /* "/bin/ls", "-l", "-h" */

		buff[0] = strtok(entireCommand, " ");
		if (_strcmp(buff[0], " ") == 0)
		{
			num++;
			free(buff[0]);
			continue;
		}
		entireCommand[readBytes - 1] = '\0';
		while (buff[i++] != NULL)
			buff[i] = strtok(NULL, " ");

		if (_strcmp(buff[0], "env") == 0)			/*if buff equal to env go to function*/
			env_function();							/*and print all enviroment varuable*/

		if (_strcmp(buff[0], "exit") == 0 && !buff[1])
			free(buff[0]), exit(ex); /*if buff equal to exit go to function and exit*/

		exit_with_arguments(buff);	/*to execute the commands*/

		if (access(buff[0], F_OK) == 0)
			ex = execuve_command_with_slash(buff, argv[0]);
		else if (_strcmp(buff[0], "env") && search_in_path(buff) == 127)
			error_message(argv[0], buff[0], num), ex = 127;
		else
			ex = 0;

		num++;
	}
}
