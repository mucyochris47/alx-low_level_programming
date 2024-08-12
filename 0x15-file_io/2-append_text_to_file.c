#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file to append to
 * @text_content: NULL terminated string to add at the end of the file
 * 
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len = 0;
    ssize_t written;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
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

