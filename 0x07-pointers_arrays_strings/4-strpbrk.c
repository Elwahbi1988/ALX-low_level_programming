#include "main.h"
/*
*_strbrk -entry point
*Description:  fonction _strbrk entry point
*@s: input
*@accept: input
*Return: always 0 (success)
*/
char *_strbrk(char *s, char *accept)
{
int k;
while (*s)
{
for (k = 0; accept[k]; k++)
{
if (*s == accept[k])
return (s);
}
s++;
}
return ('\0');
}
