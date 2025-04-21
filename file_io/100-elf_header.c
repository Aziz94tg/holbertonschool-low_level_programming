#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - prints error message and exits
 * @msg: error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * is_big_endian - checks if ELF file is big endian
 * @ident: ELF identification bytes
 * Return: 1 if big endian, 0 otherwise
 */
int is_big_endian(unsigned char *ident)
{
	return (ident[EI_DATA] == ELFDATA2MSB);
}

/**
 * swap_endian_16 - swaps byte order for uint16_t
 * @x: value to swap
 * Return: swapped value
 */
uint16_t swap_endian_16(uint16_t x)
{
	return ((x >> 8) | (x << 8));
}

/**
 * swap_endian_32 - swaps byte order for uint32_t
 * @x: value to swap
 * Return: swapped value
 */
uint32_t swap_endian_32(uint32_t x)
{
	return ((x >> 24) |
		((x >> 8) & 0x0000FF00) |
		((x << 8) & 0x00FF0000) |
		(x << 24));
}

/**
 * swap_endian_64 - swaps byte order for uint64_t
 * @x: value to swap
 * Return: swapped value
 */
uint64_t swap_endian_64(uint64_t x)
{
	return ((x >> 56) |
		((x >> 40) & 0x000000000000FF00) |
		((x >> 24) & 0x0000000000FF0000) |
		((x >> 8)  & 0x00000000FF000000) |
		((x << 8)  & 0x000000FF00000000) |
		((x << 24) & 0x0000FF0000000000) |
		((x << 40) & 0x00FF000000000000) |
		(x << 56));
}

/**
 * main - Entry point: prints ELF header
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int fd, r;
	unsigned char ident[EI_NIDENT];
	int big_endian;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	r = read(fd, ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Error: Cannot read ELF header");

	if (ident[EI_MAG0] != ELFMAG0 || ident[EI_MAG1] != ELFMAG1 ||
	    ident[EI_MAG2] != ELFMAG2 || ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");

	big_endian = is_big_endian(ident);
	printf("ELF Header:\n  Magic:   ");
	for (r = 0; r < EI_NIDENT; r++)
		printf("%02x%c", ident[r], r == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             %s\n",
	       ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("  Data:                              %s\n",
	       ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
	       "2's complement, little endian");

	printf("  Version:                           %d (current)\n", ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (ident[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	default: printf("<unknown: %x>\n", ident[EI_OSABI]); break;
	}
	printf("  ABI Version:                       %d\n", ident[EI_ABIVERSION]);

	lseek(fd, 0, SEEK_SET);
	if (ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr hdr32;
		read(fd, &hdr32, sizeof(hdr32));
		if (big_endian)
		{
			hdr32.e_type = swap_endian_16(hdr32.e_type);
			hdr32.e_entry = swap_endian_32(hdr32.e_entry);
		}
		printf("  Type:                              ");
		switch (hdr32.e_type)
		{
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		default: printf("<unknown: %x>\n", hdr32.e_type); break;
		}
		printf("  Entry point address:               %#x\n", hdr32.e_entry);
	}
	else
	{
		Elf64_Ehdr hdr64;
		read(fd, &hdr64, sizeof(hdr64));
		if (big_endian)
		{
			hdr64.e_type = swap_endian_16(hdr64.e_type);
			hdr64.e_entry = swap_endian_64(hdr64.e_entry);
		}
		printf("  Type:                              ");
		switch (hdr64.e_type)
		{
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		default: printf("<unknown: %x>\n", hdr64.e_type); break;
		}
		printf("  Entry point address:               %#lx\n", hdr64.e_entry);
	}
	close(fd);
	return (0);
}

