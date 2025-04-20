#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * error_exit - Prints an error message and exits with a given code
 * @code: The exit code
 * @message: The error message to print
 * @arg: Argument to print with the error
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, "%s %s\n", message, arg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file
 * @argc: Number of arguments
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", argv[2]);
	}

	while ((r = read(fd_from, buffer, 1024)) != 0)
	{
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(98, "Error: Can't read from file", argv[1]);
		}

		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", argv[2]);
		}
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd", argv[1]);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd", argv[2]);

	return (0);
}

