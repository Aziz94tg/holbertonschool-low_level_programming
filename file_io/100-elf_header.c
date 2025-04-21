#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - Prints an error message and exits with status 98.
 * @msg: Error message to print.
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * reverse_bytes_8 - Reverses the byte order of an unsigned long (64-bit).
 * @val: The value to reverse.
 * Return: The reversed value.
 */
unsigned long reverse_bytes_8(unsigned long val)
{
	unsigned long result;

	result = ((val & 0x00000000000000FFUL) << 56) |
	         ((val & 0x000000000000FF00UL) << 40) |
	         ((val & 0x0000000000FF0000UL) << 24) |
	         ((val & 0x00000000FF000000UL) << 8)  |
	         ((val & 0x000000FF00000000UL) >> 8)  |
	         ((val & 0x0000FF0000000000UL) >> 24) |
	         ((val & 0x00FF000000000000UL) >> 40) |
	         ((val & 0xFF00000000000000UL) >> 56);
	return (result);
}

/**
 * reverse_bytes_2 - Reverses the byte order of a 2-byte unsigned short.
 * @val: The value to reverse.
 * Return: The reversed value.
 */
unsigned short reverse_bytes_2(unsigned short val)
{
	return ((val >> 8) | (val << 8));
}

/**
 * main - Entry point. Parses and displays the ELF header of a file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, exits with 98 on error.
 */
int main(int argc, char **argv)
{
	int fd, i;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr h;
	unsigned short type;
	unsigned long entry;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Cannot open file");

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Cannot read ELF header");

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Unknown\n");

	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");

	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("lseek failed");

	r = read(fd, &h, sizeof(h));
	if (r != sizeof(h))
		print_error("Failed to read full ELF header");

	type = h.e_type;
	entry = h.e_entry;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		type = reverse_bytes_2(type);
		entry = reverse_bytes_8(entry);
	}

	printf("  Type:                              ");
	if (type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else
		printf("<unknown: %x>\n", type);

	printf("  Entry point address:               %#lx\n", entry);

	if (close(fd) == -1)
		print_error("Cannot close file");

	return (0);
}

