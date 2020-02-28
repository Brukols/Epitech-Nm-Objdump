/*
** EPITECH PROJECT, 2020
** nm
** File description:
** display_symbols
*/

#include "../include/nm.h"
#include <stdio.h>

static const char *init_fill_string(nm_t *nm)
{
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS32) {
        return ("%08lx %c %s\n");
    }
    return ("%016lx %c %s\n");
}

static const char *init_empty_string(nm_t *nm)
{
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS32) {
        return ("         %c %s\n");
    }
    return ("                 %c %s\n");
}

void display_symbols(nm_t *nm)
{
    symbol_t *symbols = init_symbols(nm);
    symbol_t *it = symbols;
    const char *fill_str = init_fill_string(nm);
    const char *empty_str = init_empty_string(nm);

    for (; it; it = it->next) {
        if (it->addr == 0) {
            printf(empty_str, it->letter, it->name);
        } else {
            printf(fill_str, it->addr, it->letter, it->name);
        }
    }

    free_symbols(symbols);
}