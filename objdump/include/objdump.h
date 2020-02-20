/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** objdump?h
*/

#ifndef OBJDUMP_H
#define OBJDUMP_H

#include <elf.h>
#include "macros.h"
#include "flags.h"
#include <stdbool.h>
#include <string.h>

typedef struct phdr_s phdr_t;
typedef struct objdump_s objdump_t;
typedef struct shdr_s shdr_t;

struct shdr_s
{
    Elf32_Shdr *shdr32;
    Elf64_Shdr *shdr64;
    size_t (*get_sh_name)(objdump_t *this);
    size_t (*get_sh_type)(objdump_t *this);
    size_t (*get_sh_flags)(objdump_t *this);
    size_t (*get_sh_addr)(objdump_t *this);
    size_t (*get_sh_offset)(objdump_t *this);
    size_t (*get_sh_size)(objdump_t *this);
    size_t (*get_sh_link)(objdump_t *this);
    size_t (*get_sh_info)(objdump_t *this);
    size_t (*get_sh_addralign)(objdump_t *this);
    size_t (*get_sh_entsize)(objdump_t *this);
};

struct phdr_s
{
    Elf32_Phdr *phdr32;
    Elf64_Phdr *phdr64;
    size_t (*get_p_type)(objdump_t *this);
    size_t (*get_p_offset)(objdump_t *this);
    size_t (*get_p_vaddr)(objdump_t *this);
    size_t (*get_p_paddr)(objdump_t *this);
    size_t (*get_p_filesz)(objdump_t *this);
    size_t (*get_p_memsz)(objdump_t *this);
    size_t (*get_p_flags)(objdump_t *this);
    size_t (*get_p_align)(objdump_t *this);
};

struct objdump_s
{
    int fd;
    void *buf;
    char *path;
    int flags;
    Elf64_Ehdr *ehdr;
    phdr_t phdr;
    shdr_t shdr;
};

size_t get_p_type(objdump_t *this);
size_t get_p_offset(objdump_t *this);
size_t get_p_vaddr(objdump_t *this);
size_t get_p_paddr(objdump_t *this);
size_t get_p_filesz(objdump_t *this);
size_t get_p_memsz(objdump_t *this);
size_t get_p_flags(objdump_t *this);
size_t get_p_align(objdump_t *this);

size_t get_sh_name(objdump_t *this);
size_t get_sh_type(objdump_t *this);
size_t get_sh_flags(objdump_t *this);
size_t get_sh_addr(objdump_t *this);
size_t get_sh_offset(objdump_t *this);
size_t get_sh_size(objdump_t *this);
size_t get_sh_link(objdump_t *this);
size_t get_sh_info(objdump_t *this);
size_t get_sh_addralign(objdump_t *this);
size_t get_sh_entsize(objdump_t *this);

#include "prototypes.h"

#endif /* !OBJDUMP_H */
