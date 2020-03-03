/*
** EPITECH PROJECT, 2020
** wrong_type
** File description:
** objdump
*/

#include "objdump.h"
#include <stdio.h>

bool wrong_type(elf_t *obj)
{
    if (obj->ehdr.get_e_type(obj) == ET_NONE) {
        fprintf(stderr, "objdump: %s: unknown type\n", obj->path);
    } else if (obj->ehdr.get_e_type(obj) == ET_CORE) {
        fprintf(stderr, "objdump: %s: core file", obj->path);
    }
    return (false);
}