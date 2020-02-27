/*
** EPITECH PROJECT, 2020
** nm
** File description:
** list_is_not_sort
*/

#include "../../include/nm.h"

bool list_is_not_sort(symbol_t *symbols)
{
    for (; symbols->next; symbols = symbols->next) {
        if (compare_symbols(symbols->name, symbols->next->name) > 0)
            return (true);
    }
    return (false);
}