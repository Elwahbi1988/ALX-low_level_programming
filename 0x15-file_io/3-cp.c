#include <stdio.h>
#include <stdlib.h>
#include "main.h"
char *create_buffer(char *file);
void close_file(int fd);
/**
*create_buffer - allocate 1024bytes to buffer
*@file: File of buffer storing for chars
*Return: Pointer tje new allocate buffer
*/
char *create_buffer(char *file)
{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}
/**
*close_file - close file descriptors
*@fd: File descriptor to close
*/
void close_file(int fd)
{
int c;
c = close(fd);
if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
/**
*main - The content of file copied to another file
*@argc: Number of arguments supplied the program
*@argv: Array of pointers to the arguments
*Return: 0 (success)
*Description: If argument count is incorrect - Exit 97
*if file_from not exist or not read - Exit 98
*if file_to not created or written - Exit 99
*if file_from or file_to not closed - Exit 100
*/
int main(int argc, char *argv[])
{
int to, from, r, w;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[1]);
free(buffer);
exit(98);
}
w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (r > 0);
free(buffer);
close_file(from);
close_file(to);
return (0);
}
