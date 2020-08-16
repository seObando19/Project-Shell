#include "holberton.h"

/**
 * prompt - Prints prompt in color
 *@void: value void
 *Return: void
*/
void prompt(void)
{
	printf("\x1B[1;33m$\x1B[0m ");

}
/**
 * listenread - get char the client terminal & call fn until char is '\n'
 *@buffer: pointer
 * Return: 1 is successful, -1 if error.
 */
int listenread(char *buffer)
{
	size_t bufsize = SIZEBUFFER;
	ssize_t c;

	fflush(stdin);
	c = getline(&buffer, &bufsize, stdin);
	if (c == EOF)
		return (-1);
	else if (_strcmp(buffer, "exit") == 10)
		return (-1);
	return (0);
}