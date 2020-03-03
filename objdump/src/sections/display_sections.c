/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_sectioins
*/

#include "objdump.h"
#include <stdio.h>

const char *non_printable_section[] = {
    ".symtab", ".shstrtab", ".strtab", NULL
};

static bool name_non_printable(const char *name)
{
    for (size_t i = 0; non_printable_section[i]; i++) {
        if (strcmp(non_printable_section[i], name) == 0)
            return (true);
    }
    return (false);
}

int display_sections(objdump_t *obj)
{
    const char *name;

    for (size_t i = 1; i < obj->ehdr.get_e_shnum(obj); i++) {
        name = obj->shdr.addrstrtable + obj->shdr.get_sh_name(obj, i);
        if (obj->shdr.get_sh_type(obj, i) == SHT_NOBITS)
            continue;
        if (name_non_printable(name))
            continue;
        printf("Contents of section %s:\n", name);
        display_bytes(obj, i);
    }
    return (SUCCESS);
}