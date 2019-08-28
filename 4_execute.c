#include "shell.h"

/**
  * builtin_func - Redirect to builtin functions.
  * @builtin_func: Redirect to builtin functions.
  * Return: 1 if _help works, 0 if exit works.
  */

int (*builtin_func[])(char **args, char *input) = {
	&_cd,
	&_help,
	&hsh_exit
};

/**
  * _execute - Execute builtin process.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: _launch(args).
  */
int _execute(char **args, char *input)
{
	char *builtin_str[] = {"cd", "help", "exit"};
	int i;

	if (args[0] == NULL)
		return (1);

	/*if (_strcmp(args[0], "cd") == 0)*/
		/*return (_cd(args));*/

	for (i = 0; i < 3; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args, input));
	}
	return (_launch(args));
}

