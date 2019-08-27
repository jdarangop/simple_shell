#include "shell.h"

/**
  * builtin_func - Redirect to builtin functions.
  * @builtin_func: Redirect to builtin functions.
  * Return: 1 if _help works, 0 if exit works.
  */

int (*builtin_func[])(void) = {
	&_help,
	&hsh_exit
};

/**
  * _execute - Execute builtin process.
  * @args: List of arguments passed from parsing.
  * Return: _launch(args).
  */
int _execute(char **args)
{
	char *builtin_str[] = {"help", "exit"};
	int i;

	if (args[0] == NULL)
		return (1);

	if (_strcmp(args[0], "cd") == 0)
		return (_cd(args));

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])());
	}
	return (_launch(args));
}

