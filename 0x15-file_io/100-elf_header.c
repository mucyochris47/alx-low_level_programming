#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/* Function prototypes */
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident);
void print_data(unsigned char e_ident);
void print_version(unsigned char e_ident);
void print_osabi(unsigned char e_ident);
void print_abi_version(unsigned char e_ident);
void print_type(unsigned int e_type);
void print_entry(unsigned long int e_entry);
void display_elf_header(const char *filename);

/* Display ELF header */
void display_elf_header(const char *filename)
{
    int fd;
    Elf64_Ehdr header;
    ssize_t bytes_read;

    /* Open the file */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error");
        exit(98);
    }

    /* Read the ELF header */
    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
    {
        perror("Error");
        close(fd);
        exit(98);
    }

    /* Close the file */
    close(fd);

    /* Check if the file is an ELF file */
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

    /* Display the ELF header information */
    printf("ELF Header:\n");
    printf("  Magic:   ");
    print_magic(header.e_ident);
    print_class(header.e_ident[EI_CLASS]);
    print_data(header.e_ident[EI_DATA]);
    print_version(header.e_ident[EI_VERSION]);
    print_osabi(header.e_ident[EI_OSABI]);
    print_abi_version(header.e_ident[EI_ABIVERSION]);
    print_type(header.e_type);
    print_entry(header.e_entry);
}

/* Print magic bytes */
void print_magic(unsigned char *e_ident)
{
    int i;

    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", e_ident[i]);
        if (i == EI_NIDENT - 1)
            printf("\n");
    }
}

/* Print ELF class */
void print_class(unsigned char e_ident)
{
    switch (e_ident)
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %02x>\n", e_ident);
            break;
    }
}

/* Print data encoding */
void print_data(unsigned char e_ident)
{
    switch (e_ident)
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %02x>\n", e_ident);
            break;
    }
}

/* Print ELF version */
void print_version(unsigned char e_ident)
{
    if (e_ident == EV_CURRENT)
        printf("1 (current)\n");
    else
        printf("<unknown: %02x>\n", e_ident);
}

/* Print OS ABI */
void print_osabi(unsigned char e_ident)
{
    switch (e_ident)
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64 UNIX\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
        default:
            printf("<unknown: %02x>\n", e_ident);
            break;
    }
}

/* Print ABI version */
void print_abi_version(unsigned char e_ident)
{
    printf("%d\n", e_ident);
}

/* Print ELF type */
void print_type(unsigned int e_type)
{
    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
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
            printf("<unknown: %02x>\n", e_type);
            break;
    }
}

/* Print entry point address */
void print_entry(unsigned long int e_entry)
{
    printf("0x%lx\n", e_entry);
}

/* Main function */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    display_elf_header(argv[1]);

    return 0;
}

