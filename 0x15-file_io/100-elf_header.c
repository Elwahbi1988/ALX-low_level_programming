#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>

void check_elf(unsigned char *e_ident);
void close_elf(int elf);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abiversion(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
/**
*check_elf - check file is elf file
*@e-ident: Pointer an array content the elf magic number
*Description:if file not elf file - Exit (98)
*/
void check_elf(unsigned char *e_ident)
{
int i;
for ( i = 0; i < 4; i++)
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
*@e-ident: Pointer an array content the elf magic number
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
printf("<unknow: %x>\n", e-ident[EI_CLASS]);
}
}
/**
*print_data - print  the data of elf header
*@e_ident: pointer an array content the elf class
*/
void print_data(unsigned char *e_ident)
{
printf("Data:");
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
*@e-ident: Pointer an array content elf version
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
*print_osabi - printf os/abi of elf header
*@e_ident: Pointer an array content the elf version
*/
void print_osabi(unsigned char *e_ident)
{
printf("OS/ABI:\n");
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
*print_abiversion - print abi version of elf header
*@e_ident: Pointer an array content the elf abi version
*/
void print_abiversion(unsigned char *e_ident)
{
printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
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
:wq

