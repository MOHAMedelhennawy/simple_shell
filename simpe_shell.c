#include "shell.h"

int main(int __attribute__((unused)) argc, char *argv[])
{
	size_t len = 0, num = 1, sss;
	char *buff[] = {NULL}, *pathBuf;
	ssize_t readBytes;
  	struct stat st;

	while ('T')
	{
		if (isatty(STDIN_FILENO) != 0) /*sfj */
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		readBytes = getline(&buff[0], &len, stdin);
			getline_error(readBytes, &buff[0]);

		if (strcmp(buff[0], "\n") == 0)
				continue;			

		buff[0][readBytes - 1] = '\0';

		if (strcmp(buff[0], "env") == 0)
			env_function();

		if (strcmp(buff[0], "exit") == 0) /** asfsadf*/
			free(buff[0]), exit(EXIT_SUCCESS);
		
		sss = strlen(buff[0]) + 1;
		pathBuf = malloc(sizeof(char) * sss); /* Don't forget to FREEEEE pathBuf ((DONE))  */
	
		_strcpy(pathBuf, buff[0]);

		buff[0] = strtok(buff[0], " "); 
		if (stat(buff[0], &st) == 0 || !buff[0])
			execuve_command_with_slash(&buff[0], argv[0], num);

		else if (strcmp(buff[0], "env") && search_in_path(pathBuf) == -1)
				error_message(argv[0], buff[0], num);	
 		free(pathBuf);
		num++;
	}
}
