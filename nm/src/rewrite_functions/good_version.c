/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_verison
*/

#include "../../include/nm.h"
#include <stdio.h>

bool good_version(nm_t *nm)
{
    if (nm->ehdr.ehdr64->e_version == EV_NONE) {
        fprintf(stderr, "nm: %s: invalid version", nm->path);
        return (false);
    }
    return (true);
}