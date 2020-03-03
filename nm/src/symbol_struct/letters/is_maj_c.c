/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "nm.h"

bool is_maj_c(nm_t *nm, int i)
{
    if (nm->sym.get_st_shndx(nm, i) == SHN_COMMON)
        return (true);
    return (false);
}