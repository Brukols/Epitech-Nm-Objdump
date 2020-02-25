/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_machine
*/

#include "../../include/elf_struct.h"
#include <stdio.h>

bool good_machine(elf_t *obj)
{
    if (obj->ehdr->e_machine == EM_NONE) {
        fprintf(stderr, "objdump: %s: unknown machine", obj->path);
        return (false);
    }
    return (true);
}