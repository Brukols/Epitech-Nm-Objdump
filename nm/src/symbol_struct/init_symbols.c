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
    symbols->letter = 'T';
    return (symbols);
}

symbol_t *init_symbols(nm_t *nm)
{
    symbol_t *symbols = NULL;
    symbol_t *first = NULL;

    for (size_t i = 0; i < nm->sym.size; i++) {
        if (nm->sym.get_st_name(nm, i) == 0)
            continue;
        symbols = insert_symbol(symbols, nm, i);
        if (!symbols)
            return (NULL);
        if (!first)
            first = symbols;
    }
    return (first);
}