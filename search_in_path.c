#include "shell.h"
/**
 * search_in_path - to search if this path is exist or not.
 *
 * @buf: the command to concat with nodes
 * and check if is exist or not.
 *
 * Return: 0 if path is exist, 127 if not.
 */
int search_in_path(char **buf)
{
	d_node *head = build_linkedList();

	if (check_node_for_execuve(&head, buf) == 0)
	{
		free_list(head);
		return (127);
	}

	free_list(head);
	return (0);
}

/**
 * check_node_for_execuve - to search if this path is exist or not.
 * @head: pointer to first node.
 * @buffer: pointer to command to concat
 * Return: 0 if path is exist, 1 if not.
 */
int check_node_for_execuve(d_node **head, char **buffer)
{
	char *str;
	int flag;
	/*concat the command with each char and check*/
	/*if is exist or not, if true execuve it*/
	/*else return error massage*/
	while (head != NULL)
	{
		str = malloc(sizeof(char) * (_strlen((*head)->directory) +
			 _strlen(buffer[0]) + 2));

		_strcpy(str, (*head)->directory);
		_strcat(str, "/");					/*conact the command with each dir*/
		_strcat(str, buffer[0]);			/*to check if is exist*/

		if (access(str, F_OK) == 0)			/*if exist execuve it*/
		{
			if (fork() == 0)
			{
				buffer[0] = str;
				execve(buffer[0], buffer, NULL);
				exit(EXIT_SUCCESS);
			}
			wait(NULL), flag = 1;
			break;
		}
		else if ((*head)->nextDir == NULL)
		{
			free((*head)->nextDir), flag = 0;
			break;
		}
		else
		{
			d_node *temp = *head;
			*head = (*head)->nextDir;
			free(temp->directory);
			free(temp), free(str);
		}
	}
	free(str);
	return (flag);
}
