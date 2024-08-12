#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message and exits with the specified code
 * @code: exit code
 * @msg: error message
 * @file: filename related to the error
 */
void error_exit(int code, const char *msg, const char *file)
{
    dprintf(STDERR_FILENO, msg, file);
    exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits with code on error
 */
int main(int argc, char *argv[])
{
    int file_from, file_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to\n", "");

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);

    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1)
        error_exit(99, "Error: Can't write to %s\n", argv[2]);

    while ((read_bytes = read(file_from, buffer, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(file_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            error_exit(99, "Error: Can't write to %s\n", argv[2]);
    }

    if (read_bytes == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);

    if (close(file_from) == -1)
        error_exit(100, "Error: Can't close fd %d\n", argv[1]);

    if (close(file_to) == -1)
        error_exit(100, "Error: Can't close fd %d\n", argv[2]);

    return (0);
}

