#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <errno.h>
#include <string.h>

void print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void display_elf_header(int fd)
{
    Elf64_Ehdr ehdr;
    ssize_t read_bytes;

    // Read the ELF header
    read_bytes = read(fd, &ehdr, sizeof(ehdr));
    if (read_bytes != sizeof(ehdr))
    {
        print_error("Can't read from file");
    }

    // Check ELF magic number
    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr.e_ident[EI_MAG3] != ELFMAG3)
    {
        print_error("Not an ELF file");
    }

    // Print ELF Header information
    printf("ELF Header:\n");
    printf("  Magic:   %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n",
           ehdr.e_ident[EI_MAG0], ehdr.e_ident[EI_MAG1], ehdr.e_ident[EI_MAG2], ehdr.e_ident[EI_MAG3],
           ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD],
           ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD],
           ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD], ehdr.e_ident[EI_PAD]);

    printf("  Class:                             ");
    if (ehdr.e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (ehdr.e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("<unknown: %x>\n", ehdr.e_ident[EI_CLASS]);

    printf("  Data:                              ");
    if (ehdr.e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (ehdr.e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("<unknown: %x>\n", ehdr.e_ident[EI_DATA]);

    printf("  Version:                           %d (current)\n", ehdr.e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (ehdr.e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("UNIX - AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_ident[EI_OSABI]);
            break;
    }

    printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (ehdr.e_type)
    {
        case ET_NONE:
            printf("NONE (None)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_type);
            break;
    }

    printf("  Entry point address:               0x%lx\n", ehdr.e_entry);
}

int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Can't read from file");
    }

    display_elf_header(fd);

    close(fd);
    return 0;
}

