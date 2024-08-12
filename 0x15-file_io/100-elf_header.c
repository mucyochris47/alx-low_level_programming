#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_header - Prints the ELF header of a file
 * @header: Pointer to the ELF header
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x\n",
           header->e_ident[0], header->e_ident[1],
           header->e_ident[2], header->e_ident[3]);
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header->e_type)
    {
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(97);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Not a valid ELF file\n");
        close(fd);
        exit(98);
    }

    if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
        header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not a valid ELF file\n");
        close(fd);
        exit(98);
    }

    print_elf_header(&header);

    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }

    return (0);
}

