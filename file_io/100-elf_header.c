#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints error message and exits with code 98.
 * @msg: Error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - Display ELF header information
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd, i;
	ssize_t r;
	unsigned char e[EI_NIDENT];
	Elf64_Ehdr h;
	uint16_t type;
	unsigned long entry;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Cannot open file");

	r = read(fd, e, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Cannot read ELF header");

	if (e[EI_MAG0] != ELFMAG0 || e[EI_MAG1] != ELFMAG1 ||
	    e[EI_MAG2] != ELFMAG2 || e[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             %s\n",
	       e[EI_CLASS] == ELFCLASS32 ? "ELF32" :
	       e[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");

	printf("  Data:                              %s\n",
	       e[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       e[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
	       "Unknown");

	printf("  Version:                           %d (current)\n", e[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (e[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	default: printf("<unknown: %x>\n", e[EI_OSABI]); break;
	}

	printf("  ABI Version:                       %d\n", e[EI_ABIVERSION]);

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("lseek failed");

	if (read(fd, &h, sizeof(h)) != sizeof(h))
		print_error("Failed to read full ELF header");

	type = h.e_type;
	entry = h.e_entry;

	if (e[EI_DATA] == ELFDATA2MSB)
	{
		type = (type >> 8) | (type << 8);
		entry = ((entry & 0x00000000000000FFUL) << 56) |
		        ((entry & 0x000000000000FF00UL) << 40) |
		        ((entry & 0x0000000000FF0000UL) << 24) |
		        ((entry & 0x00000000FF000000UL) << 8) |
		        ((entry & 0x000000FF00000000UL) >> 8) |
		        ((entry & 0x0000FF0000000000UL) >> 24) |
		        ((entry & 0x00FF000000000000UL) >> 40) |
		        ((entry & 0xFF00000000000000UL) >> 56);
	}

	printf("  Type:                              ");
	switch (type)
	{
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	default: printf("<unknown: %x>\n", type); break;
	}

	printf("  Entry point address:               %#lx\n", entry);

	close(fd);
	return (0);
}

