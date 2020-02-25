/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_version
*/

#include "../../include/elf_struct.h"
#include <stdio.h>

bool good_version(elf_t *obj)
{
    if (obj->ehdr->e_version == EV_NONE) {
        fprintf(stderr, "objdump: %s: invalid version", obj->path);
        return (false);
    }
    return (true);
}