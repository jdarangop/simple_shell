#include "shell.h"

/**
  * _cd - Change the directory.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _cd(char **args, __attribute__((unused)) char *input)
{
	if (args[1] == NULL)
	{
		perror("hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh:");
		}
	}
	return (1);
}
/**
  * _help - Display the help about a command.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
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
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if works.
  */
int hsh_exit(__attribute__((unused)) char **args, char *input)
{
	int var;

	if (args[1] == NULL)
		return (0);

	var = _atoi(args[1]);

	if (var < 0)
	{
		perror("hsh:");
		return (1);
	}
	else if (var == 0)
	{
		return (0);
	}
	else if (var >= 256)
	{
		free(input);
		free(args);
		exit(var - 256);
	}
	else
	{
		free(input);
		free(args);
		exit(var);
	}
}

/**
  * _env - Display the environ in the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _env(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{
		/*int len = _strlen(*ep);*/

		_puts(environ[i]);
		_puts("\n");
		/*write(STDOUT_FILENO, *ep, len);*/
		/*write(STDOUT_FILENO, "\n", 1);*/
		i++;
	}
	return (1);
}
