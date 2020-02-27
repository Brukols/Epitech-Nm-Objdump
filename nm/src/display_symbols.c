/*
** EPITECH PROJECT, 2020
** nm
** File description:
** display_symbols
*/

#include "../include/nm.h"
#include <stdio.h>

void display_symbols(nm_t *nm)
{
    symbol_t *symbols = init_symbols(nm);
    symbol_t *it = symbols;

    for (; it; it = it->next) {
        if (it->addr == 0) {
            printf("                 %c %s\n", it->letter, it->name);
        } else {
            printf("%016lx %c %s\n", it->addr, it->letter, it->name);
        }
    }

    free_symbols(symbols);
}