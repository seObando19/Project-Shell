#include "holberton.h"
#include <signal.h>

/**
  * main - Entry to launch program
  * @argc: argument counter
  * @argv: arguments
  * @env: environment var
  * Return: 1.
  */
int main(int argc, char **argv, char **env)
{
	/** pointer save data input of the terminal client */
	char *line;
	/* char *argv2[] = {__FILE__, NULL}; */
	int _isatty;      /*test whether a file descriptor*/
	int statusbuffer = 0;
	int status_pid = 0;
	char *_ARGS_PATH[] = {"/bin/",
"/sbin/", "/usr/local/sbin/", "/usr/local/bin/",
"/usr/sbin/", "/usr/bin/", "/snap/bin/", NULL};
	signal(SIGINT, intHandler); /*interrupt from keyboard*/
	_isatty = isatty(0);
	while (1)
	{
	if (_isatty != 0)
		prompt();
	if (argc == 1)
	{
		line = malloc(sizeof(char) * SIZEBUFFER + 1);
		if (!line)
			exit(100);
		line[SIZEBUFFER] = '\0';
		statusbuffer = listenread(line);
		if (statusbuffer == -1)
		{
			free(line);
			exit(status_pid);
		}
	}
	status_pid = get_simple_args(argc, argv, line, _ARGS_PATH, env);
	fflush(stdin);
	fflush(stdout);
	if (_isatty == 0)
		exit(status_pid);
	}
	return (status_pid);
}
