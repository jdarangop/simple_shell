#include "shell.h"

/**
  * _cd - Change the directory.
  * @args: List of arguments passed from parsing.
  * Return: 1 if works.
  */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
/**
  * _help - Display the help about a command.
  * Return: 1 if works.
  */
int _help(void)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
  * hsh_exit - Exit to the shell.
  * Return: 0 if works.
  */
int hsh_exit(void)
{
	return (0);
}

/**
  * _env - Display the environ in the shell.
  * Return: 1 if works.
  */
int _env(void)
{
	char **ep = environ;

	while (*ep != NULL)
	{
		int len = _strlen(*ep);

		write(STDOUT_FILENO, *ep, len);
		ep++;
	}
	return (1);
}
