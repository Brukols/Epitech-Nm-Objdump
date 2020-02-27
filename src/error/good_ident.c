/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_ident
*/

#include "../../include/elf_struct.h"
#include <stdio.h>
#include <stdbool.h>

bool good_ident(elf_t *obj)
{
    const int bytes[] = {
        0, 1, 2, 3, 6
    };
    const char defines[] = {
        ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, EV_CURRENT
    };

    for (size_t i = 0; i < 5; i++) {
        if (obj->ehdr.ehdr64->e_ident[bytes[i]] != defines[i])
            return (wrong_file_format(obj));
    }
    if (obj->ehdr.ehdr64->e_ident[4] == ELFCLASSNONE)
        return (wrong_file_format(obj));
    if (obj->ehdr.ehdr64->e_ident[5] == ELFDATANONE)
        return (wrong_file_format(obj));
    return (true);
}