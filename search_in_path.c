#include "shell.h"

int search_in_path(char *buf)
{
    d_node *head = build_linkedList();
    char *str, **buffer;/* char *buffer[] = {"Ls", "-l", NULL} */
    int flag = 1, i = 0, args = 1, j = 0;

    while (buf[i] != '\0') /* {"ls -l -h /tmp"}*/
    {
        if (buf[i] == ' ')
            args++;
        i++;
    }
    buffer = malloc(sizeof(char *) * (args + 1)); /**/


    buffer[0] = strtok(buf, " "); /* "ls"   */
    /*    // puts(buffer[0]);*/
    while (buffer[j++] != NULL)
    {
        buffer[j] = strtok(NULL, " "); /*, "-l", "-h"*/
        /*        // printf("%s ", buffer[i]);*/
    }
    /*    // buffer[args] = NULL; */
    while (head != NULL)
    {                                 /* //      /usr/bin    /       ls   '\0'*/
        str = malloc(sizeof(char) * (strlen(head->directory) + strlen(buffer[0]) + 2));
        /*        // if (str == NULL) <------------------------------------------------- LOOK
        // {
        //     free(buffer);
        //     free_list(head);
        //     return (-1);
        // }*/
        strcpy(str, head->directory); /* str = usr/bin/ls   */
        strcat(str, "/");
        strcat(str, buffer[0]);
    
        if (access(str, F_OK) == 0)
        {
            if (fork() == 0)
            {
                buffer[0] = str;
                /* usr/bin/ls  -l -h /root */
                execve(buffer[0], buffer, NULL);
                free(buffer[0]); 
                free(buffer);
                free_list(head);
                exit(0);
            }
            wait(NULL);
            flag = 1;
            break;
        }
        if (head->nextDir == NULL) /* // ls->/bin/-> null */
            flag = 0;

        head = head->nextDir;
        free(str);
    }
    if (flag == 0)
    {
        free(buffer);
        free_list(head);
        return (-1);
    }
    // free(environ);
    free_list(head);
    return (1);
}
