#include "shell.h"

/**
 * print_environment - print the environment.
 * return: void
*/
void print_environment(void)
{
char **env = environ;

while (*env != NULL)
{
size_t len = _strlen(*env);
write(STDOUT_FILENO, *env, len);
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
