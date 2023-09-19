#include "shell.h"
/**
 * main - the main function to execute our own shell.
 * @argc: number of arguments.
 * @argv: the passed arguments to program.
 * Return: return
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	size_t len = 0, num = 1, sss, ex = EXIT_SUCCESS;
	char *buff[] = {NULL}, *pathBuf, *exitBuf;
	ssize_t readBytes;

	while ('T')
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		readBytes = getline(&buff[0], &len, stdin);
			getline_error(readBytes, &buff[0], &ex);
		if (_strcmp(buff[0], "\n") == 0)
		{
			num++;
			continue;
		}
		buff[0][readBytes - 1] = '\0';
		if (_strcmp(buff[0], "env") == 0)				/*if buff equal to env go to function*/
			env_function();								/*and print all enviroment varuable*/

		if (_strcmp(buff[0], "exit") == 0)				/*if buff equal to exit go to function*/
			free(buff[0]), exit(ex);					/*and exit*/
		exitBuf = malloc(sizeof(char) * (_strlen(buff[0]) + 1));		/*store in heap*/
		_strcpy(exitBuf, buff[0]);
		exit_with_arguments(exitBuf, &buff[0]);					/*to execute the command with arguments*/
		pathBuf = malloc(sizeof(char) * (_strlen(buff[0]) + 1));
		_strcpy(pathBuf, buff[0]);
		buff[0] = _strtok(buff[0], " ");
		if (access(buff[0], F_OK) == 0 || !buff[0])
			ex = execuve_command_with_slash(&buff[0], argv[0], num, &pathBuf);

		else if (_strcmp(buff[0], "env") && search_in_path(pathBuf) == 127)
			error_message(argv[0], buff[0], num), ex = 127;
		else
			ex = 0;
		free(pathBuf), num++;
	}
}
