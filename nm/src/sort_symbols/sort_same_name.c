/*
** EPITECH PROJECT, 2020
** nm
** File description:
** sort name
*/

#include "nm.h"
#include <ctype.h>

static int special_cmp(const char *s1, const char *s2)
{
    int result_cmp = strcasecmp(s1, s2);
    size_t i_s1 = 0;
    size_t i_s2 = 0;

    if (result_cmp != 0)
        return (result_cmp);
    for (size_t i = 0; s1[i]; i++) {
        for (; s1[i_s1] && !isalnum(s1[i_s1]); i_s1++);
        for (; s2[i_s2] && !isalnum(s2[i_s2]); i_s2++);
        if (s1[i_s1] > s2[i_s2])
            return (-1);
        if (s1[i_s1] < s2[i_s2])
            return (1);
        if (s1[i_s1])
            i_s1++;
        if (s2[i_s2])
            i_s2++;
    }
    if (s1[i_s1] > s2[i_s2])
        return (-1);
    return ((s1[i_s1] < s2[i_s2] ? 1 : 0));
}

static symbol_t *compare_first(symbol_t *symbols, symbol_t **fs)
{
    symbol_t *first = NULL;
    symbol_t *second = NULL;

    if (special_cmp(symbols->name, symbols->next->name) <= 0)
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
            symbols = (symbols->next ? symbols->next : symbols);
            continue;
        }
        if (!last) {
            last = compare_first(symbols, &first);
            symbols = (symbols->next ? symbols->next : symbols);
            continue;
        } else if (special_cmp(symbols->name, symbols->next->name) > 0)
            symbols = swap_list(last);
        last = symbols;
        symbols = (symbols->next ? symbols->next : symbols);
    }
    return (first);
}