/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "../../../include/nm.h"

bool is_maj_a(nm_t *nm, int i)
{
    if (nm->sym.get_st_shndx(nm, i) == SHN_ABS)
        return (true);
    return (false);
}