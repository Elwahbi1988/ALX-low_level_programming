#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
*main - multiplies two integers
*@argc: number of arguments
*@argv: array of arguments
*Return: 0 (success), 1 (Error)
*/
int main(int argc, char *argv[])
{
int a, b;
if (argc == 3)
{
a = atoi(argv[1]);
b = atoi(argv[2]);
printf("%d\n", a *b);
return (0);
}
printf("Error\n");
return (1);
}
