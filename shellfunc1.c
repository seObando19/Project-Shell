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
/**
 * get_simple_args - this fn splits the string when space char is found
 *@argc: argument counter
 *@argv: where the arguments are contained
 *@args: arguments
 *@_path: path
 *@ev: pointer that contain enviroment vars
 * Return: status of execution
 */
int get_simple_args(int argc, char **argv, char *args, char **_path, char **ev)
{
	char delim[] = " \n";
	char **options;
	char *argx;
	int j = 0;
	int args_max = 255, status_pid = 0;
	(void)_path;

	if (argc == 1)
	{
		if ((int)args[0] == 10)
			free(args);
		else
		{
			options = malloc(sizeof(char *) * args_max);
			if (options == NULL)
			{
				free(options);
				exit(111);
			}
			argx = strtok(args, delim);
			while (argx != NULL)
			{options[j] = argx;
				argx = strtok(NULL, delim);
				j++; }
			options[j] = NULL;
			if (_strcmp(options[0], "env") == 0 && options[1] == NULL)
				printenv(ev);
			else if (options[0] != NULL && _strlen(options[0]) > 0)
				status_pid = pid_launch(options, args, _path);
			free(args);
			free(options);
		}
	}
	else if (argc >= 2)
	{
		args_nval(argv);
		status_pid = pid_launch(argv, NULL, _path);
	}
	return (status_pid);
}
