/*
** EPITECH PROJECT, 2020
** nm
** File description:
** sort_symbols
*/

#include "nm.h"

symbol_t *sort_symbols(symbol_t *symbols)
{
    if (!list_is_not_sort(symbols))
        return (sort_same_name(symbols));
    return (sort_symbols(sort(symbols)));
}