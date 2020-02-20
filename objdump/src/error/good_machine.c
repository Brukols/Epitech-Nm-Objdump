/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_machine
*/

#include "../../include/objdump.h"
#include <stdio.h>

bool good_machine(objdump_t *obj)
{
    if (obj->ehdr->e_machine == EM_NONE) {
        fprintf(stderr, "objdump: %s: unknown machine", obj->path);
        return (false);
    }
    return (true);
}