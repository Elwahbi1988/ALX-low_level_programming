#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_elf(unsigned char *e_ident);
void close_elf(int elf);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
/**
*check_elf - check file is elf file
*@e_ident: Pointer an array content the elf magic number
*Description:if file not elf file - Exit (98)
*/
void check_elf(unsigned char *e_ident)
{
int i;
for (i = 0; i < 4; i++)
{
if (e_ident[i] != 127 && e_ident[i] != 'E'
&& e_ident[i] != 'L' && e_ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
*print_magic - print numbers magic of elf header
*@e_ident: Pointer an array content the elf magic number
*Description: The magic number is separated to space
*/
void print_magic(unsigned char *e_ident)
{
int i;
printf("Magic:");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", e_ident[i]);
if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
*print_class - print class of elf header
*@e_ident: Pointer an array content the elf class
*/
void print_class(unsigned char *e_ident)
{
printf("Class:");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknow: %x>\n", e_ident[EI_CLASS]);
}
}

/**
*print_data - print  the data of elf header
*@e_ident: pointer an array content the elf class
*/
void print_data(unsigned char *e_ident)
{
printf("Data:     ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknow: %x>\n", e_ident[EI_CLASS]);
}
}

/**
*print_version - print the version of elf header
*@e_ident: Pointer an array content elf version
*/
void print_version(unsigned char *e_ident)
{
printf("Version: %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf("(current)\n");
break;
default:
printf("\n");
break;
}
}

/**
*print_osabi- printf os/abi of elf header
*@e_ident: Pointer an array content the elf version
*/
void print_osabi(unsigned char *e_ident)
{
printf("OS/ABI:        ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - LINUX\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
*print_abi- print abi version of elf header
*@e_ident: Pointer an array content the elf abi version
*/
void print_abi(unsigned char *e_ident)
{
printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
*print_type - print type of elf header
*@e_type: Type of elf
*@e_ident: Pointer an array content the elf class
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf("Type:");
switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x\n", e_type);
}
}

/**
*print_entry - prints the entry point of elf header
*@e_ident: Pointer an array content the elf class
*@e_entry: Address of elf entry point
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("Entry point address:");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
else
printf("%#lx\n", e_entry);
}

/**
*close_elf - close file elf
*@elf: File descriptor of file elf
*Description: File not be closed - Exit (98)
*/
void close_elf(int elf)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
exit(98);
}

/**
*main - elf header in the information contained at the start elf file
*@argc: Number of argument to the program
*@argv: Array of pointers to arguments
*Return: (0) success
*Description: File is not elf file or fails the function - Exite (98)
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;
o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
exit(98);
}
check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);
free(header);
close_elf(o);
return (0);
}
