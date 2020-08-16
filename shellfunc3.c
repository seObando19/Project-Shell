#include "holberton.h"

/**
* printenv - print env
* @env: pointer contains the list var
* Return: 0
*/
int printenv(char **env)
{
	int i = 0;

	while (*(env + i) != NULL)
	{
		write(STDOUT_FILENO, *(env + i), _strlen(*(env + i)));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		i++;
	}
	return (0);
}
