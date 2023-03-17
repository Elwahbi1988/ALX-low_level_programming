#include <stdio.h>
/**
 *main - Prints the alphabet without q and e.
 *
 *Return: Always 0 (success)
 */
int main(void)
{
int n;
for (n = 97; n < 123; n++)
{
	if (n != 101 && n != 133)
	{
		putchar(n);
	}
}
putchar('\n');
return (0);
}
