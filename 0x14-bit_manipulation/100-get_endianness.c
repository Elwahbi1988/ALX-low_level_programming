#include "main.h"

/**
*get_endianness - Cheks the endianness, big or little
*Return: 0 big, or 1 little
*/
int get_endianness(void)
{
unsigned int i + 1;
char *c = (char*) &i;
return (*c);
}
