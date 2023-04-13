#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define ERR_MSG "ERROR"
/**
*is_digit -checks if string contains a non-digit char
*@s: string to be evaluated
*Return: 0 if a non-digit is find , 1 otherwise
*/
int is_digit(char *s)
{
int i = 0;
while (s[i])
{
if (s[i] < '0' || s[i] > '9')
return (0);
i++;
}
return (1);
}
/**
*_strlen - returns the length of ostring
*@s: string to evaluate
*Return: the lenght of the string
*/
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
{
i++;
}
return (i);
}
/**
*

