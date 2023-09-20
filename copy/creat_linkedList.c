#include "shell.h"

/**
 * build_linkedList - creat list.
 *
 * Description: This function creat a linked list for the given
 * environment variable PATH and splits it to parts with strtok
 * each directory in node.
 *
 * Return: The head of the list to access to the whole linked list.
 */
d_node *build_linkedList(void)
{
	char *pathValue, *dirPath;
	d_node *head = NULL, *pttr = NULL, *newDir;

	pathValue = _getenv("PATH"); /* Get the value of path (all directories) */

	dirPath = _strtok(pathValue, ":"); /* splits each directory */
	while (dirPath != NULL)
	{
		/* Create new node for each directory */
		newDir = malloc(sizeof(struct dirNode));
		newDir->directory = _strdup(dirPath); /* Take a copy form directory */
		newDir->nextDir = NULL;

		if (head != NULL)
		{
			pttr = head; /* Make pointer point to head */
			while (pttr->nextDir != NULL)
				pttr = pttr->nextDir; /* Reach to end of list */
			/* Make the last node in list points to the new directory */
			pttr->nextDir = newDir;
		}
		else
			head = newDir; /* Make the head points to the first node */

		dirPath = _strtok(NULL, ":"); /* Continue in splits the path to dirs */
	}
	free(pathValue); /* After build the list free the value of path */
	return (head); /* and return head (access to whole list) */
}

/**
 * free_list - free whole linked list
 *
 * @head: the head node to access for all nodes.
 *
 * Discription: This functoin free all nodes until reach to
 * the end of list, free node value and the whole node.
 *
 * Return: Nothing (void)
 */
void free_list(d_node *head)
{
	d_node *pntr = head, *next_node;

	while (pntr != NULL)
	{
		next_node = pntr->nextDir;	/* next_node points to the next node in list */
		/* Free value of current node and the whole node */
		free(pntr->directory), free(pntr);
		pntr = next_node; /* Move to next directory */
	}
}
