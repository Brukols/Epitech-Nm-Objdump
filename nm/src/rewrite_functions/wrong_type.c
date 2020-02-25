/*
** EPITECH PROJECT, 2020
** wrong_type
** File description:
** objdump
*/

#include "../../include/nm.h"
#include <stdio.h>

bool wrong_type(elf_t *obj)
{
    if (obj->ehdr->e_type == ET_NONE) {
        fprintf(stderr, "nm: %s: unknown type\n", obj->path);
    } else if (obj->ehdr->e_type == ET_CORE) {
        fprintf(stderr, "nm: %s: core file", obj->path);
    }
    return (false);
}