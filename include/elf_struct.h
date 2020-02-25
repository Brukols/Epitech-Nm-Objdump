/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** objdump?h
*/

#ifndef ELF_H
#define ELF_H

#include <elf.h>
#include <string.h>
#include <stdbool.h>
#include "macros.h"
#include "flags.h"

typedef struct phdr_s phdr_t;
typedef struct elf_s elf_t;
typedef struct shdr_s shdr_t;

struct shdr_s
{
    void *addrstrtable;
    Elf32_Shdr *shdr32;
    Elf64_Shdr *shdr64;
    size_t (*get_sh_name)(elf_t *, size_t);
    size_t (*get_sh_type)(elf_t *, size_t);
    size_t (*get_sh_flags)(elf_t *, size_t);
    size_t (*get_sh_addr)(elf_t *, size_t);
    size_t (*get_sh_offset)(elf_t *, size_t);
    size_t (*get_sh_size)(elf_t *, size_t);
    size_t (*get_sh_link)(elf_t *, size_t);
    size_t (*get_sh_info)(elf_t *, size_t);
    size_t (*get_sh_addralign)(elf_t *, size_t);
    size_t (*get_sh_entsize)(elf_t *, size_t);
    void *(*get_addrstrtable)(elf_t *);
};

struct phdr_s
{
    Elf32_Phdr *phdr32;
    Elf64_Phdr *phdr64;
    size_t (*get_p_type)(elf_t *);
    size_t (*get_p_offset)(elf_t *);
    size_t (*get_p_vaddr)(elf_t *);
    size_t (*get_p_paddr)(elf_t *);
    size_t (*get_p_filesz)(elf_t *);
    size_t (*get_p_memsz)(elf_t *);
    size_t (*get_p_flags)(elf_t *);
    size_t (*get_p_align)(elf_t *);
};

struct elf_s
{
    int fd;
    void *buf;
    char *path;
    int flags;
    Elf64_Ehdr *ehdr;
    phdr_t phdr;
    shdr_t shdr;
};

size_t get_p_type(elf_t *);
size_t get_p_offset(elf_t *);
size_t get_p_vaddr(elf_t *);
size_t get_p_paddr(elf_t *);
size_t get_p_filesz(elf_t *);
size_t get_p_memsz(elf_t *);
size_t get_p_flags(elf_t *);
size_t get_p_align(elf_t *);

size_t get_sh_name(elf_t *, size_t);
size_t get_sh_type(elf_t *, size_t);
size_t get_sh_flags(elf_t *, size_t);
size_t get_sh_addr(elf_t *, size_t);
size_t get_sh_offset(elf_t *, size_t);
size_t get_sh_size(elf_t *, size_t);
size_t get_sh_link(elf_t *, size_t);
size_t get_sh_info(elf_t *, size_t);
size_t get_sh_addralign(elf_t *, size_t);
size_t get_sh_entsize(elf_t *, size_t);
void *get_addrstrtable(elf_t *, size_t index);

#include "prototypes.h"

#endif /* !OBJDUMP_H */
