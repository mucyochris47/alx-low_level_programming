#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void check_error(int check, char *msg, int fd_from, int fd_to)
{
    if (check == -1)
    {
        if (fd_from != -1)
            close(fd_from);
        if (fd_to != -1)
            close(fd_to);
        dprintf(STDERR_FILENO, "%s\n", msg);
        exit(98);
    }
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    check_error(fd_from, "Error: Can't read from file", -1, -1);

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    check_error(fd_to, "Error: Can't write to file", fd_from, -1);

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            check_error(-1, "Error: Can't write to file", fd_from, fd_to);
    }
    check_error(read_bytes, "Error: Can't read from file", fd_from, fd_to);

    check_error(close(fd_from), "Error: Can't close fd", -1, fd_to);
    check_error(close(fd_to), "Error: Can't close fd", -1, -1);

    return (0);
}

