/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_has_reloc
*/

#include "../../../include/objdump.h"

int flag_has_reloc(objdump_t *obj)
{
    if (obj->ehdr->e_type == ET_REL)
        return (HAS_RELOC);
    return (0);
}