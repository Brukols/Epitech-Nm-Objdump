/*
** EPITECH PROJECT, 2020
** nm
** File description:
** sort name
*/

#include "../../include/nm.h"

static symbol_t *compare_first(symbol_t *symbols, symbol_t **fs)
{
    symbol_t *first = NULL;
    symbol_t *second = NULL;

    if (symbols->next->name[0] != '_')
        return (symbols);
    first = symbols->next;
    second = symbols->next->next;
    first->next = symbols;
    symbols->next = second;
    (*fs) = first;
    return (NULL);
}

symbol_t *sort_same_name(symbol_t *symbols)
{
    symbol_t *first = symbols;

    for (symbol_t *last = NULL; symbols->next;) {
        if (compare_symbols(symbols->name, symbols->next->name) != 0) {
            last = symbols;
            symbols = symbols->next;
            continue;
        }
        if (!last) {
            last = compare_first(symbols, &first);
            symbols = symbols->next;
            continue;
        } else if (symbols->next->name[0] == '_')
            symbols = swap_list(last);
        last = symbols->next;
        if (symbols->next->next) {
            symbols = symbols->next->next;
        } else
            break;
    }
    return (first);
}