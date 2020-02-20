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
};

size_t get_p_type(objdump_t *this);
size_t get_p_offset(objdump_t *this);
size_t get_p_vaddr(objdump_t *this);
size_t get_p_paddr(objdump_t *this);
size_t get_p_filesz(objdump_t *this);
size_t get_p_memsz(objdump_t *this);
size_t get_p_flags(objdump_t *this);
size_t get_p_align(objdump_t *this);

#include "prototypes.h"

#endif /* !OBJDUMP_H */
