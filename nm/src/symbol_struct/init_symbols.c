/*
** EPITECH PROJECT, 2020
** nm
** File description:
** int_symbols
*/

#include "../../include/nm.h"
#include "../../include/utility.h"
#include <stdio.h>
#include <stdlib.h>

const section_t sections[] = {
    {'w', &is_min_w},
    {'W', &is_maj_w},
    {'u', &is_min_u},
    {'U', &is_maj_u},
    {'v', &is_min_v},
    {'V', &is_maj_v},
    {'a', &is_min_a},
    {'A', &is_maj_a},
    {'c', &is_min_c},
    {'C', &is_maj_c},
    {'b', &is_min_b},
    {'B', &is_maj_b},
    {'r', &is_min_r},
    {'R', &is_maj_r},
    {'d', &is_min_d},
    {'D', &is_maj_d},
    {'t', &is_min_t},
    {'T', &is_maj_t}
};

static char init_letter(nm_t *nm, int i)
{
    for (size_t a = 0; a < 18; a++) {
        if (sections[a].ptr(nm, i) == true)
            return (sections[a].letter);
    }
    return ('?');
}

static symbol_t *insert_symbol(symbol_t *symbols, nm_t *nm, int i, char c)
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
    symbols->letter = c;
    return (symbols);
}

static bool is_a_file(nm_t *nm, int i)
{
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS32) {
        if (ELF32_ST_TYPE(nm->sym.get_st_info(nm, i)) \
== STT_FILE)
            return (true);
    }
    if (nm->ehdr.get_e_ident(nm)[EI_CLASS] == ELFCLASS64) {
        if (ELF64_ST_TYPE(nm->sym.get_st_info(nm, i)) \
== STT_FILE)
            return (true);
    }
    return (false);
}

symbol_t *init_symbols(nm_t *nm)
{
    symbol_t *symbols = NULL;
    symbol_t *first = NULL;
    char c;

    for (size_t i = 0; i < nm->sym.size; i++) {
        if (nm->sym.get_st_name(nm, i) == 0)
            continue;
        if (is_a_file(nm, i))
            continue;
        c = init_letter(nm, i);
        symbols = insert_symbol(symbols, nm, i, c);
        if (!symbols)
            return (NULL);
        if (!first)
            first = symbols;
    }
    return (sort_symbols(first));
}