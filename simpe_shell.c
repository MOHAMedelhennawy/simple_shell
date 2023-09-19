#include "shell.h"

int main(int __attribute__((unused)) argc, char *argv[])
{
	size_t len = 0, num = 1, sss, ex = EXIT_SUCCESS;
	char *buff[] = {NULL}, *pathBuf, *exitBuf;
	ssize_t readBytes;
  	struct stat st;

	while ('T')
	{
		if (isatty(STDIN_FILENO) != 0) /*sfj */
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		readBytes = getline(&buff[0], &len, stdin);
			getline_error(readBytes, &buff[0], &ex);

		if (_strcmp(buff[0], "\n") == 0)
		{
			num++;
			continue;
		}

		buff[0][readBytes - 1] = '\0';

		if (_strcmp(buff[0], "env") == 0)
			env_function();

		if (_strcmp(buff[0], "exit") == 0) /** asfsadf*/
			free(buff[0]), exit(ex);
		
		exitBuf = malloc(sizeof(char) * (_strlen(buff[0]) + 1));
		_strcpy(exitBuf, buff[0]);
		exit_with_arguments(exitBuf, &buff[0]);


		
	
		pathBuf = malloc(sizeof(char) * (_strlen(buff[0]) + 1)); /* Don't forget to FREEEEE pathBuf ((DONE))  */
		_strcpy(pathBuf, buff[0]);

		buff[0] = _strtok(buff[0], " "); 
		if (stat(buff[0], &st) == 0 || !buff[0])
			ex = execuve_command_with_slash(&buff[0], argv[0], num, &pathBuf, &exitBuf);

		else if (_strcmp(buff[0], "env") && (ex = search_in_path(pathBuf)) == 127)
				error_message(argv[0], buff[0], num);

 		free(pathBuf);
		num++;
	}
}
