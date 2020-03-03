/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "nm.h"

bool is_maj_w(nm_t *nm, int i)
{
    if (nm->sym.sym64 && ELF64_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_WEAK)
        return (true);
    if (nm->sym.sym32 && ELF32_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_WEAK)
        return (true);
    return (false);
}