/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_has_syms
*/

#include "../../include/elf_struct.h"
#include <stdio.h>

int flag_has_syms(elf_t *obj)
{
    char *name;

    for (size_t i = 0; i < obj->ehdr.get_e_shnum(obj); i++) {
        name = obj->shdr.addrstrtable + obj->shdr.get_sh_name(obj, i);
        if (!strcmp(name, ".dynsym") || !strcmp(name, ".symtab"))
            return (HAS_SYMS);
    }
    return (0);
}