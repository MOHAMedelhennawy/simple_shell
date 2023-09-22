#include "shell.h"

/**
 * _getenv - get value of given variable
 *
 * @name: name of environment variable.
 *
 * Description: This function get the value or environment
 * variable (name=value).
 *
 * Return: The value of given name.
 */
char *_getenv(char *name)
{
	int i = 0;
	char *varName, *value, *newValueCpy, *envCpy;

	if (!name || !environ)
		return (NULL);
	while (environ[i] != NULL) /* Check for each environment variable */
	{
		envCpy = _strdup(environ[i]); /* Take a copy from the variable */
		varName = _strtok(envCpy, "="); /* Splits the name from value */
		if (_strcmp(name, varName) == 0)
		{
			value = _strtok(NULL, "\0"); /* Got the value of given name */
			if (!value)
				return (NULL);
			break;
		}
		free(envCpy); /* If the variable not that we want */
		i++;
	}
	if (!environ[i])
		return (NULL);
	newValueCpy = _strdup(value); /* Take a copy form the value */

	free(envCpy);
	return (newValueCpy);
}
