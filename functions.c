#include "shell.h"

/**
 * split_string - splits a string into an array of words
 * @str: input string to split
 * @delim: delimiter character to split string
 * Return: array of words (tokens).
 */

char **split_string(char *str, const char *delim)
{
char **tokens = NULL;
char *token;
int num_tokens = 0;
int i = 0;

/* count the number of tokens */
token = strtok(str, delim);
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}

/* allocate space for the tokens */
tokens = malloc(sizeof(char *) * (num_tokens + 1));
if (tokens == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

/* store each token in the array */
token = strtok(str, delim);
while (token != NULL)
{
tokens[i] = _strdup(token);
if (tokens[i] == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
token = strtok(NULL, delim);
i++;
}

/* terminate the array with a NULL pointer */
tokens[num_tokens] = NULL;

return (tokens);
}

/**
 * execute1 - carries out commands inputed by user
 * @argv: command argument taken as param
 * Return - 0 on success, error on failure.
*/

void execute1(char **argv)
{
char *command = NULL;
pid_t pid;
if (argv)
{
/* get the command */
command = argv[0];

/* check if there are any arguments */
if (argv[1] != NULL)
{
command = _strcat(argv[0], " ");
command = _strcat(command, argv[1]);
}
/* execute the command with execve */
pid = fork();
if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
if (execve(command, argv, NULL) == -1)
{
perror("Error:");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
int status;
if (wait(&status) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}
}
}
}
