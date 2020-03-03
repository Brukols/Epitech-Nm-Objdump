/*
** EPITECH PROJECT, 2020
** nml
** File description:
** sort
*/

#include "nm.h"

static symbol_t *compare_first(symbol_t *symbols, symbol_t **fs)
{
    symbol_t *first = NULL;
    symbol_t *second = NULL;

    if (compare_symbols(symbols->name, symbols->next->name) <= 0)
        return (symbols);
    first = symbols->next;
    second = symbols->next->next;
    first->next = symbols;
    symbols->next = second;
    (*fs) = first;
    return (first);
}

symbol_t *sort(symbol_t *symbols)
{
    symbol_t *first = symbols;
    symbol_t *last = NULL;

    while (symbols->next) {
        if (!last) {
            last = compare_first(symbols, &first);
            symbols = symbols->next;
            continue;
        }
        if (compare_symbols(symbols->name, symbols->next->name) > 0) {
            symbols = swap_list(last);
        }
        last = symbols;
        symbols = symbols->next;
    }
    return (first);
}