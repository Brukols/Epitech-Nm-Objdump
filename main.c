#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <elf.h>

int main(int argc, char const *argv[])
{
    int fd;
    void *buf;
    struct stat s;
    Elf64_Ehdr *ehdr;
    Elf64_Phdr *phdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;

    fd = open(argv[1], O_RDONLY);
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    ehdr = buf;
    phdr = buf + ehdr->e_phoff;
    shdr = buf + ehdr->e_shoff;
    const char *name;
    void *addr = buf + shdr[ehdr->e_shstrndx].sh_offset;
    int i_symtab = -1;
    int i_strtab = -1;
    Elf64_Sym *symtab;
    char *strtab;
    int lgt = 0;

    for (size_t i = 1; i < ehdr->e_shnum; i++) {
        name = addr + shdr[i].sh_name;
        if (strcmp(name, ".symtab") == 0) {
            symtab = (Elf64_Sym *)(buf + shdr[i].sh_offset);
            lgt = shdr[i].sh_size;
        } else if (strcmp(name, ".strtab") == 0)
            strtab = buf + shdr[i].sh_offset;
    }

    for (size_t i = 1; i < lgt / sizeof(Elf64_Sym); i++) {
        printf("Symbole : %s\n", &strtab[symtab[i].st_name]);
    }
    return 0;
}
