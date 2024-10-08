#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int ac, char **av);
int cp(const char *file_from, const char *file_to);
void print_elf_header(const char *filename);

#endif /* MAIN_H */

