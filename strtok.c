#include "shell.h"
char *_strtok(char *strin, char *delim)
{
    static char *each_char = NULL;
    char *word;
    if (strin != NULL)
        each_char = strin;


    if (!each_char || *each_char == '\0')
        return (NULL);
    
    word = each_char;
    while (*each_char != '\0')
    {
        if (*each_char == *delim)
        {
            *each_char = '\0';
            each_char++;
            return (word);
        }
        each_char++;
    }
    return (word);
}
