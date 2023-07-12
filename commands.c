#include "shell.h"

/**
 * read_command - prints prompt and reads user input.
 * @command: command
 * Return: prompt and 0
*/
ssize_t read_command(char *command)
{
char *prompt = "#cisfun$ ";
ssize_t read_bytes;
/* Check if the shell is running in interactive mode */
int interactive_mode = isatty(STDIN_FILENO);
/* printing prompt */
if (interactive_mode)
{
write(STDOUT_FILENO, prompt, _strlen(prompt));
fflush(stdout);
}
read_bytes = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
if (read_bytes == -1)
{
perror("read");
exit(EXIT_FAILURE);
}
/*Remove the trailing newline character*/
if (read_bytes > 0 && command[read_bytes - 1] == '\n')
{
command[read_bytes - 1] = '\0';
read_bytes--;
}
return (read_bytes);
}


/**
 * execute_command - checks path for command and returns
 * @command: command
 * Return: 0 success or -1 error
*/
void execute_command(char *command)
{
char *args[MAX_ARGS], *token, *full_path;
int i, status;
pid_t pid = fork();
if (pid == -1)
{
/* Error occurred during fork() */
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
i = 0;
/* Tokenize the command into arguments */
token = strtok(command, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

/* Get the full path of the command */
full_path = get_full_path(args[0]);
/* Execute the command with the full path */
execve(full_path, args, NULL);
/* If execve returns, an error occurred */
perror("execve");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
close(pid);
}
}

/**
 * get_full_path - get the full path of the command
 * @command: the command
 * Return: full path to command
*/
char *get_full_path(const char *command)
{
char *full_path = NULL, *env_path = getenv("PATH");
char *path = _strdup(env_path), *token;
if (path == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
token = strtok(path, ":");
while (token != NULL)
{
size_t dir_length = _strlen1(token);
size_t command_length = _strlen1(command);
size_t path_length = dir_length + 1 + command_length + 1;
/*dir/command + '/' + '\0'*/
if (path_length > MAX_PATH_LENGTH)
{
/*Skip this directory if the path length exceeds the limit*/
token = strtok(NULL, ":");
continue;
}
full_path = (char *)malloc(path_length * sizeof(char));
if (full_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
_strcpy(full_path, token);
_strcat1(full_path, "/");
_strcat1(full_path, command);
if (access(full_path, X_OK) == 0)
{
/*Found the executable, stop searching*/
break;
}
free(full_path);
full_path = NULL;
token = strtok(NULL, ":");
}
free(path);
return (full_path);
}
