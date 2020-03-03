/*
** EPITECH PROJECT, 2020
** nm
** File description:
** swap_list
*/

#include "nm.h"

symbol_t *swap_list(symbol_t *symbols)
{
    symbol_t *first = symbols->next;
    symbol_t *second = symbols->next->next;

    symbols->next = second;
    first->next = second->next;
    second->next = first;
    return (second);
}