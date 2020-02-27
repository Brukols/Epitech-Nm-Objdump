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

#include "../../include/macros.h"
#include "../../include/flags.h"
#include "../../include/elf_struct.h"

typedef elf_t nm_t;

typedef struct symbol_s 
{
    size_t addr;
    char letter;
    const char *name;
    struct symbol_s *next;
} symbol_t;

#include "prototypes.h"

#endif /* !OBJDUMP_H */