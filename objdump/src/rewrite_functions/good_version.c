/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_verison
*/

#include "../../include/objdump.h"
#include <stdio.h>

bool good_version(objdump_t *obj)
{
    if (obj->ehdr.ehdr64->e_version == EV_NONE) {
        fprintf(stderr, "objdump: %s: invalid version", obj->path);
        return (false);
    }
    return (true);
}