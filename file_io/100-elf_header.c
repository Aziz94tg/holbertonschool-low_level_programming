#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - Print error and exit
 * @msg: error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Print ELF header info
 * @ehdr: pointer to ELF header
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", ehdr->e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');

	printf("  Class:                             %s\n",
		ehdr->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Invalid class");

	printf("  Data:                              %s\n",
		ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		ehdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid data encoding");

	printf("  Version:                           %d (current)\n", ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	default: printf("<unknown: %x>\n", ehdr->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (ehdr->e_type)
	{
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_REL: printf("REL (Relocatable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	default: printf("<unknown: %x>\n", ehdr->e_type);
	}

	printf("  Entry point address:               %#lx\n", (unsigned long)ehdr->e_entry);
}

/**
 * main - Entry point to ELF header parser
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;
	ssize_t read_bytes;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't open file");

	read_bytes = read(fd, &ehdr, sizeof(ehdr));
	if (read_bytes != sizeof(ehdr))
		print_error("Can't read ELF header");

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
		ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
		ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
		ehdr.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	print_elf_header(&ehdr);

	close(fd);
	return (0);
}

