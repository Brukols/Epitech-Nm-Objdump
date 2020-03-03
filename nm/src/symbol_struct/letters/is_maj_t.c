/*
** EPITECH PROJECT, 2020
** nm
** File description:
** letters
*/

#include "nm.h"

bool is_maj_t(nm_t *nm, int i)
{
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == \
SHT_PROGBITS && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) \
== (SHF_ALLOC | SHF_EXECINSTR))
        return (true);
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == \
SHT_FINI_ARRAY && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) \
== (SHF_ALLOC | SHF_WRITE))
        return (true);
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == \
SHT_INIT_ARRAY && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) \
== (SHF_ALLOC | SHF_WRITE))
        return (true);
    return (false);
}