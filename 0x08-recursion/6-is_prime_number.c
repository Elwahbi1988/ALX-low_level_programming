#include "main.h"
#include <stdio.h>

int actual_prime(int n, int i)
/**
*is_prime_number - fuction return if an integer is a prome number or not
*@n: number to evaluated
*Return: (1) is a prime number, (0) is not prime number
*/
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
return (actual_prime(n, n - 1));
}
/**
*actual_prime - calculate the number is prime recursively
* @i: iterator
* @n: number to evaluated
*
*Return: (1) is prime number, (0) is not prime number
*/
int actual_prime(int n, int i)
{
if (i == 1)
{
return (1);
}
if (n % i == 0 && i > 0)
{
return (0);
}
return (actual_prime(n, i - 1));
}
