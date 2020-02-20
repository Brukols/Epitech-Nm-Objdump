/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_type
*/

#include "../../include/objdump.h"
#include <stdio.h>

bool wrong_type(objdump_t *obj)
{
    if (obj->ehdr->e_type == ET_NONE) {
        fprintf(stderr, "objdump: %s: unknown type\n", obj->path);
    } else if (obj->ehdr->e_type == ET_CORE) {
        fprintf(stderr, "objdump: %s: core file", obj->path);
    }
    return (false);
}

bool good_type(objdump_t *obj)
{
    if (obj->ehdr->e_type == ET_NONE || obj->ehdr->e_type == ET_CORE)
        return (wrong_type(obj));
    return (true);
}