#include "shell.h"

/**
 * main - simple shell
 * Return: 0
*/
int main(void)
{
char command[MAX_COMMAND_LENGTH], **tokens = NULL;
const char *delim = " \n";

while (read_command(command))
{
/* check if the getline function failed */
/* or reached EOF or user used CTRL + D */


/*check if user types in just /n*/
if (check_blank(command) || (_strcmp(command, "\n") == 0))
{
continue;
}
if (check_exit(command) || (_strcmp(command, "exit") == 0))
{
/*Print New Line Before exit*/
/*Exit the shell*/
break;
}
/*env input check*/
if (check_env(command) || (_strcmp(command, "env") == 0))
{
print_environment();
}

if (command[0] == '/')
{
/* Split the string (buffer) into an array of words*/
tokens = split_string(command, delim);
/* Execute the command*/
execute1(tokens);
}
else
{
execute_command(command);
}
}

return (0);
}
