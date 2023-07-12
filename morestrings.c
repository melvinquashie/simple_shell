#include "shell.h"

/**
 * _strlen1 - Determines length of a string.
 * @s: Constant string.
 * Return: length of the string.
 */
int _strlen1(const char *s)
{
int len = 0;
while (s[len] != '\0')
{
len++;
}
return (len);
}

/**
 * _strcat1 - Concatenates two strings.
 * @dest: pointer to destination.
 * @src: constant pointer to source.
 * Return: dest.
 */
char *_strcat1(char *dest, const char *src)
{
int dest_len = _strlen(dest);
int i;
for (i = 0; src[i] != '\0'; i++)
{
dest[dest_len + i] = src[i];
}
dest[dest_len + i] = '\0';
return (dest);
}
