/*
** EPITECH PROJECT, 2020
** wrong_type
** File description:
** objdump
*/

#include "nm.h"
#include <stdio.h>

bool wrong_type(elf_t *obj)
{
    if (obj->ehdr.get_e_type(obj) == ET_NONE) {
        fprintf(stderr, "nm: %s: unknown type\n", obj->path);
    } else if (obj->ehdr.get_e_type(obj) == ET_CORE) {
        fprintf(stderr, "nm: %s: core file\n", obj->path);
    }
    return (false);
}