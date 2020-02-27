/*
** EPITECH PROJECT, 2020
** nm
** File description:
** int_symbols
*/

#include "../../include/nm.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct section_s {
    char letter;
    const char *name;
} section_t;

static char init_letter(nm_t *nm, int i)
{
    if (nm->sym.get_st_shndx(nm, i) == STB_LOCAL)
        return ('U');
    if (nm->sym.sym32 && ELF32_ST_BIND(nm->sym.get_st_info(nm, i)) == STB_GNU_UNIQUE)
        return ('u');
    if (nm->sym.sym64 && ELF64_ST_BIND(nm->sym.get_st_info(nm, i)) == STB_GNU_UNIQUE)
        return ('u');
    if (nm->sym.sym64 && ELF64_ST_BIND(nm->sym.get_st_info(nm, i)) == STB_WEAK && ELF64_ST_TYPE(nm->sym.get_st_info(nm, i)) == STT_OBJECT) {
        if (nm->sym.get_st_shndx(nm, i) == SHN_UNDEF)
            return ('v');
        return ('V');
    }
    if (nm->sym.sym32 && ELF32_ST_BIND(nm->sym.get_st_info(nm, i)) == STB_WEAK && ELF32_ST_TYPE(nm->sym.get_st_info(nm, i)) == STT_OBJECT) {
        if (nm->sym.get_st_shndx(nm, i) == SHN_UNDEF)
            return ('v');
        return ('V');
    }
    if (nm->sym.get_st_shndx(nm, i) == SHN_ABS)
        return ('A');
    if (nm->sym.get_st_shndx(nm, i) == SHN_COMMON)
        return ('C');
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == SHT_NOBITS && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) == (SHF_ALLOC | SHF_WRITE))
        return ('B');
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == SHT_PROGBITS && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) == SHF_ALLOC)
        return ('R');
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == SHT_PROGBITS && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) == (SHF_ALLOC | SHF_WRITE))
        return ('D');
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == SHT_PROGBITS && nm->shdr.get_sh_flags(nm, nm->sym.get_st_shndx(nm, i)) == (SHF_ALLOC | SHF_EXECINSTR))
        return ('T');
    if (nm->shdr.get_sh_type(nm, nm->sym.get_st_shndx(nm, i)) == SHT_DYNAMIC)
        return ('D');
    return ('?');
}

static symbol_t *insert_symbol(symbol_t *symbols, nm_t *nm, int i)
{
    if (!symbols) {
        symbols = malloc(sizeof(symbol_t));
        if (!symbols)
            return (NULL);
    } else {
        symbols->next = malloc(sizeof(symbol_t));
        if (!symbols->next)
            return (NULL);
        symbols = symbols->next;
    }
    symbols->next = NULL;
    symbols->name = nm->sym.get_symbol_name(nm, i);
    symbols->addr = nm->sym.get_st_value(nm, i);
    symbols->letter = init_letter(nm, i);
    return (symbols);
}

symbol_t *init_symbols(nm_t *nm)
{
    symbol_t *symbols = NULL;
    symbol_t *first = NULL;

    for (size_t i = 0; i < nm->sym.size; i++) {
        if (nm->sym.get_st_name(nm, i) == 0)
            continue;
        if (nm->sym.get_st_shndx(nm, i) == SHN_ABS)
            continue;
        symbols = insert_symbol(symbols, nm, i);
        if (!symbols)
            return (NULL);
        if (!first)
            first = symbols;
    }
    return (sort_symbols(first));
}