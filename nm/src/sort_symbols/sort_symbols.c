/*
** EPITECH PROJECT, 2020
** nm
** File description:
** sort_symbols
*/

#include "../../include/nm.h"

static symbol_t *swap_list(symbol_t *symbols)
{
    symbol_t *first = symbols->next;
    symbol_t *second = symbols->next->next;

    symbols->next = second;
    first->next = second->next;
    second->next = first;
    return (second);
}

static symbol_t *sort(symbol_t *symbols)
{
    symbol_t *first = symbols;
    symbol_t *last = NULL;

    while (symbols->next) {
        if (compare_symbols(symbols->name, symbols->next->name) > 0) {
            first = (!last ? symbols->next : first);
            symbols = swap_list((!last ? symbols : last));
        }
        last = symbols;
        symbols = symbols->next;
    }
    return (first);
}

symbol_t *sort_symbols(symbol_t *symbols)
{
    while (list_is_not_sort(symbols)) {
        symbols = sort(symbols);
    }
    return (symbols);
}