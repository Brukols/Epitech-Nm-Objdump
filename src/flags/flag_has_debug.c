/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** has_debug
*/

#include "../../include/elf_struct.h"

int flag_has_debug(elf_t *obj)
{
    char *name;

    for (size_t i = 0; i < obj->ehdr->e_shnum; i++) {
        name = obj->shdr.addrstrtable + obj->shdr.get_sh_name(obj, i);
        if (!strcmp(name, ".debug"))
            return (HAS_SYMS);
    }
    return (0);
}