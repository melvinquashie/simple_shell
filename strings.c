#include "shell.h"
/* String functions */

/**
 * _strcpy - Copy a string from one memory location to another.
 * @dest: Pointer to destination memory location.
 * @src: Pointer to source.
 * Return: Pointer to destination string.
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];
dest[i] = src[i];

return (dest);
}

/**
 * _strlen - Determines length of a string.
 * @s: The string.
 * Return: length of the string.
 */
int _strlen(char *s)
{
int len = 0;

while (s[len] != '\0')
len++;

return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: integer ret > 0 if s1 is smaller than s2, < 0 if bigger or
 * = 0 if srings are the same.
 */
int _strcmp(char *s1, char *s2)
{
int ret = 0;

while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
ret = *s1 - *s2;
return (ret);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: pointer to destination.
 * @src: pointer to source.
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
char *str = dest;

while (*str)
str++;
while (*src)
*str++ = *src++;
*str = '\0';
return (dest);
}

/**
 * _strdup -  duplicates a string.
 * @str: string given as parameter.
 * Return: NULL if str = NULL. On success, the _strdup function returns a
 * pointer to the duplicated string.
 * It returns NULL if insufficient memory was
 * available.
 */
char *_strdup(char *str)
{
char *cpy, *tmp;
int len = 0;

if (str == NULL)
return (NULL);
while (str[len] != '\0')
len++;
cpy = malloc(sizeof(char) * (len + 1));
if (cpy == NULL)
return (NULL);
tmp = cpy;
while (*str)
*tmp++ = *str++;
*tmp = '\0';
return (cpy);
}
