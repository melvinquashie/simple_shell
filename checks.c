#include "shell.h"

/**
 * check_exit - checks if user input is exit and exits loop.
 * @input: input string
 * Return: 1 on success, 0 on failure.
*/
int check_exit(char *input)
{
char *command = "exit\n";
if (_strcmp(input, command) == 0)
{
return (1);
}

return (0);
}

/**
 * check_blank - checks if user input is just a return
 * @input: string to compare to "\n"
 * Return: 1 if user_input is equal to '\n', 0 otherwise
 */

int check_blank(char *input)
{
if (input[0] == '\n')
{
return (1);
}

return (0);
}

/**
 * check_env - checks if user input is env
 * @input: string to compare to
 * Return: 0
*/
int check_env(char *input)
{
if (_strcmp(input, "env") == 0)
{
return (1);
}
return (0);
}
