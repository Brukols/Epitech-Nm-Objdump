/*
** EPITECH PROJECT, 2020
** nm
** File description:
** sort name
*/

#include "../../include/nm.h"

static bool cmp_symbols(symbol_t *symbols)
{
    if (strcmp(symbols->name, symbols->next->name) > 0 && symbols->value == symbols->next->value)
        return (true);
    if (symbols->value > symbols->next->value)
        return (true);
    return (false);
}

static symbol_t *compare_first(symbol_t *symbols, symbol_t **fs)
{
    symbol_t *first = NULL;
    symbol_t *second = NULL;

    if (cmp_symbols(symbols) == false)
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
        } else if (cmp_symbols(symbols) == true)
            symbols = swap_list(last);
        last = symbols;
        symbols = symbols->next;
    }
    return (first);
}