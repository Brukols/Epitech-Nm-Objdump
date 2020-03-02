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

static symbol_t *compare_first(symbol_t *last, symbol_t *symbols, symbol_t **fs)
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
    return (NULL);
}

static symbol_t *sort(symbol_t *symbols)
{
    symbol_t *first = symbols;
    symbol_t *last = NULL;

    while (symbols->next) {
        if (!last) {
            last = compare_first(last, symbols, &first);
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

static symbol_t *compare_first_(symbol_t *last, symbol_t *symbols, symbol_t **fs)
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

static symbol_t *sort_same_name(symbol_t *symbols)
{
    symbol_t *first = symbols;
    symbol_t *last = NULL;

    while (symbols->next) {
        if (compare_symbols(symbols->name, symbols->next->name) != 0) {
            last = symbols;
            symbols = symbols->next;
            continue;
        }
        if (!last) {
            last = compare_first_(last, symbols, &first);
            symbols = symbols->next;
            continue;
        }
        if (symbols->next->name[0] == '_') {
            symbols = swap_list(last);
        }
        last = symbols->next;
        if (symbols->next->next) {
            symbols = symbols->next->next;
        } else
            break;
    }
    return (first);
}

symbol_t *sort_symbols(symbol_t *symbols)
{
    if (!list_is_not_sort(symbols))
        return (sort_same_name(symbols));
    return (sort_symbols(sort(symbols)));
}