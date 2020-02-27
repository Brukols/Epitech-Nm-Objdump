/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "../../../include/nm.h"

bool is_maj_v(nm_t *nm, int i)
{
    if (nm->sym.sym64 && ELF64_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_WEAK && ELF64_ST_TYPE(nm->sym.get_st_info(nm, i)) == \
STT_OBJECT && nm->sym.get_st_shndx(nm, i) != SHN_UNDEF)
        return (true);
    if (nm->sym.sym32 && ELF32_ST_BIND(nm->sym.get_st_info(nm, i)) \
== STB_WEAK && ELF32_ST_TYPE(nm->sym.get_st_info(nm, i)) == \
STT_OBJECT && nm->sym.get_st_shndx(nm, i) != SHN_UNDEF)
        return (true);
    return (false);
}