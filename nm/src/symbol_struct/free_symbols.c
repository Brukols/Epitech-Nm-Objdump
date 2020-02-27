/*
** EPITECH PROJECT, 2020
** nm
** File description:
** destroy_symbols
*/

#include "../../include/nm.h"
#include <stdlib.h>

void free_symbols(symbol_t *symbols)
{
    symbol_t *tmp = NULL;

    for (; symbols; symbols = symbols->next) {
        if (tmp)
            free(tmp);
        tmp = symbols;
    }
    if (tmp)
        free(tmp);
}