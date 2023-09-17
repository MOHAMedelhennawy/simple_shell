#include "shell.h"

int search_in_path(char *buf)
{
    d_node *head = build_linkedList();
    char *str, **buffer;/* char *buffer[] = {"Ls", "-l", NULL} */
    int flag = 1, i = 0, args = 1, j = 0;

    while (buf[i] != '\0') /* {"ls -l -h /tmp"}*/
    {
        if (buf[i] == ' ' && buf[i + 1] != '\0')
            args++;
        i++;
    }
    buffer = malloc(sizeof(char *) * (args + 1)); /**/


    buffer[0] = strtok(buf, " "); /* "ls"   */

    while (buffer[j++] != NULL)
        buffer[j] = strtok(NULL, " "); /*, "-l", "-h"*/

    if (check_node_for_execuve(&head, buffer) == 0)
    {
        free_list(head);
        return (-1);
    }
    free_list(head);

    return (1);
}

int check_node_for_execuve(d_node **head, char **buffer)
{
    char *str;
    int flag;

    while (head != NULL)
    {                                 /* //      /usr/bin    /       ls   '\0'*/
        str = malloc(sizeof(char) * (_strlen((*head)->directory) + _strlen(buffer[0]) + 2));

        _strcpy(str, (*head)->directory); /* str = usr/bin/ls   */
        concatenate_string(str, "/");
        concatenate_string(str, buffer[0]);
    
        if (access(str, F_OK) == 0)
        {
            if (fork() == 0)
            {
                buffer[0] = str;
                execve(buffer[0], buffer, NULL);/* usr/bin/ls  -l -h /root */
                exit(EXIT_SUCCESS);
            }
            wait(NULL), flag = 1;
            break;
        }
        else if ((*head)->nextDir == NULL) /* // ls->/bin/-> null */
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
    free (str), free(buffer);

    return (flag);
}
