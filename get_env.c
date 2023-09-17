#include "shell.h"
char *_getenv(const char *name)
{
    int i = 0;
    char *varName, *value, *valuCpy;
    char *cpy;
    while (environ[i] != NULL)
    {
        cpy = strdup(environ[i]);
        varName = strtok(cpy, "=");
        if (strcmp(name, varName) == 0)
        {
            value = strtok(NULL, "\0");
            break;
        }
        free(cpy);
        i++;    
    }
    valuCpy = strdup(value);

    free(cpy);
    return (valuCpy);
}
