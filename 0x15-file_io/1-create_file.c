#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * 
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len = 0;
    ssize_t written;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[len])
            len++;

        written = write(fd, text_content, len);
        if (written == -1 || written != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

