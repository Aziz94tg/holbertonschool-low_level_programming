#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - Prints an error message to stderr and exits.
 * @code: Exit code.
 * @msg: Error message to print.
 * @filename: Optional file name.
 */
void error_exit(int code, const char *msg, const char *filename)
{
	if (filename)
		dprintf(STDERR_FILENO, "%s %s\n", msg, filename);
	else
		dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, exits with various codes on error.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", argv[2]);
	}

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", argv[2]);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file", argv[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd", argv[1]);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd", argv[2]);

	return (0);
}

