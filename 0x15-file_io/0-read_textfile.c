#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buffer;
    ssize_t fd;
    ssize_t nread;
    ssize_t nwrite;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buffer = malloc(letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

    nread = read(fd, buffer, letters);
    if (nread == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    nwrite = write(STDOUT_FILENO, buffer, nread);
    free(buffer);
    close(fd);

    if (nwrite != nread)
        return (0);

    return (nwrite);
}

