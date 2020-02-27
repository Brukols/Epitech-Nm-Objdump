/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_has_reloc
*/

#include "../../include/elf_struct.h"

int flag_has_reloc(elf_t *obj)
{
    if (obj->ehdr.get_e_type(obj) == ET_REL)
        return (HAS_RELOC);
    return (0);
}