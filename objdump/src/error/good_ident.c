/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_ident
*/

#include "../../include/objdump.h"
#include <stdio.h>

bool wrong_file_format(objdump_t *obj)
{
    fprintf(stderr, "objdump: %s: file format not recognized\n", obj->path);
    return (false);
}

bool good_ident(objdump_t *obj)
{
    if (obj->ehdr->e_ident[0] != ELFMAG0)
        return (wrong_file_format(obj));
    if (obj->ehdr->e_ident[1] != ELFMAG1)
        return (wrong_file_format(obj));
    if (obj->ehdr->e_ident[2] != ELFMAG2)
        return (wrong_file_format(obj));
    if (obj->ehdr->e_ident[3] != ELFMAG3)
        return (wrong_file_format(obj));
    return (true);
}