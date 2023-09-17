#include "shell.h"
d_node *build_linkedList(void)
{
    char *allDirs, *dir;
    d_node *head = NULL, *pttr = NULL, *new;

    allDirs = _getenv("PATH");
    
    dir = strtok(allDirs, ":");
    while (dir != NULL)
    {     
        new = malloc(sizeof(struct dirNode));
        new->directory = strdup(dir);
        new->nextDir = NULL;

        if (head == NULL)
            head = new;
        else
        {
            pttr = head;

            while (pttr->nextDir != NULL)
                pttr = pttr->nextDir;
        
            pttr->nextDir = new;
        }
        dir = strtok(NULL, ":");
    }
    free(allDirs);
    return (head);
}
