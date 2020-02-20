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
    const int bytes[] = {
        0, 1, 2, 3, 6
    };
    const char defines[] = {
        ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, EV_CURRENT
    };

    for (size_t i = 0; i < 5; i++) {
        if (obj->ehdr->e_ident[bytes[i]] != defines[i])
            return (wrong_file_format(obj));
    }
    if (obj->ehdr->e_ident[4] == ELFCLASSNONE)
        return (wrong_file_format(obj));
    if (obj->ehdr->e_ident[5] == ELFDATANONE)
        return (wrong_file_format(obj));
    return (true);
}