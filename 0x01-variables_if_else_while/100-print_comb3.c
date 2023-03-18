#include <stdio.h>
/**
  *main - Prints all possible different combinations of two digits.
  *
  *Return: Always 0 (success)
  */
int main(void)
{
int n, m;
for (n = 48; m <= 56; m++)
{
for (m = 49; m <= 57; m++)
{
if (m > n)
{
putchar(n);
putchar(m);
if (n != 56 || m != 57)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
return (0);
}
