#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include <elf.h>

union data {
    Elf64_Shdr *shdr;
    Elf32_Shdr *shdr2;
};

union phdr {
    Elf64_Phdr *_64;
    Elf32_Phdr *_32;
};

int main(int argc, char const *argv[])
{
    struct stat s;

    int fd = open(argv[1], O_RDONLY);
    void *buf;
    fstat(fd, &s);

    Elf64_Ehdr *ehdr = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    switch (ehdr->e_ident[4])
    {
    case ELFCLASS32:
        printf("%ld\n", ((Elf32_Ehdr*)ehdr)->e_type);
        break;
    case ELFCLASS64:
        printf("%ld\n", ehdr->e_type);
        break;
        default:
        printf("nop\n");
    }
    return 0;
}
