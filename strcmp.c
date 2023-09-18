#include "shell.h"


int _strcmp(char *strin1, char *strin2)
{
	int i, strcm;

	strcm = 0;
	for (i = 0; (strin1[i] != '\0' || strin2[i] != '\0'); i++)
	{
		if (strin1[i] != strin2[i])
		{
			strcm = strin1[i] - strin2[i];
            if (strcm > 0)
                return (1);
            else
                return (-1);
		}
	}
	return (0);
}
