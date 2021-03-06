/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "nm.h"

bool is_min_v(nm_t *nm, int i)
{
    if (is_maj_v(nm, i) && nm->sym.get_st_shndx(nm, i))
        return (true);
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS32) {
        if (is_maj_v(nm, i) && ELF32_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_LOCAL)
            return (true);
    }
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS64) {
        if (is_maj_v(nm, i) && ELF64_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_LOCAL)
            return (true);
    }
    return (false);
}