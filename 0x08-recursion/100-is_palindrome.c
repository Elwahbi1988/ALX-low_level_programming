#inclued "main.h"
/**
  *is_palindrome - fuction checks if a string is a palindrome
  *@s: string to reverse
  *Return: (1) if it is palindrome, (0) it's not
  */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (check_pal(s, 0, _strlen_recursion(s)));
}
/**
  *_strlen_recursion - return the length of string
  *@s: strin to calculate the length 
  *Return: length of the string
  */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
  *check_pal - chech the charaters recursively for palindrome
  *@s: string to check
  *@i : iterator
  *@len: length of the string
  *Return: (1) if it is palindrome, (0) it's not
  */
int check_pal(char *s, int i, unt len)
{	
	if (*(s+i) != *(s + len - 1))
	return (0);
	if (i >= len)
	return (1);
	return (check_pal(s, i + 1, len - 1));
}
