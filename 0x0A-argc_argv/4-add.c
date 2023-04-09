#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
/**
*check_num -cheeck - string there are digit
*@str: array str
*Return: always 0 (success)
*/
int check_num(char *str)
{
/*declaring variables*/
unsigned int count;
count = 0;
while (count < strlen(str)) /*count string*/
{
if (!isdigit(str[count])) /*chech if str there are digit */
{
return (0);
}
count++;
}
return (1);
}

/**
* main - Print the name of the program
*@argc: Count arguments
*@argv: Arguments
*Return: Always 0 (success)
*/
int main(int argc, char *argv[])
{
/*declaring variables*/
int count;
int str_to_int;
int sum = 0;
count = 1;
/*goes through the whole array*/
while (count < argc)
{
/*atoi convert string to int*/
if (check_num(argv[count]))
{
str_to_int = atoi(argv[count]);
sum += str_to_int;
}
/*condition if one of the number contains symbols that are note digits*/
else
{
printf("Error\n");
return (1);
}
count++;
}
/*print sum */
printf("%d\n",sum);
return (0);
}
