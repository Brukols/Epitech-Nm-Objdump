/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** include
*/

#ifndef NM_H
#define NM_H

#include <elf.h>
#include <stdbool.h>
#include <string.h>

#include "macros.h"
#include "flags.h"
#include "elf_struct.h"

typedef elf_t nm_t;

typedef struct symbol_s
{
    size_t shndx;
    size_t value;
    char letter;
    const char *name;
    struct symbol_s *next;
} symbol_t;

#include "prototypes.h"

#endif /* !OBJDUMP_H */