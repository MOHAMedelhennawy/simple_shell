#include "shell.h"

char *_getenv(char *name)
{
    int i = 0;
    char *varName, *value, *valuCpy;
    char *cpy;
    while (environ[i] != NULL)
    {
        cpy = _strdup(environ[i]);
        varName = _strtok(cpy, "=");
        if (_strcmp(name, varName) == 0)
        {
            value = _strtok(NULL, "\0");
            break;
        }
        free(cpy);
        i++;    
    }
    valuCpy = _strdup(value);

    free(cpy);
    return (valuCpy);
}
