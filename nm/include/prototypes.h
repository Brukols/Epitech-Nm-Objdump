/*
** EPITECH PROJECT, 2020
** nm
** File description:
** prototypes
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "nm.h"

int nm(int ac, char **av);
int display_informations(char *path);

void display_symbols(nm_t *nm);
symbol_t *init_symbols(nm_t *nm);
void free_symbols(symbol_t *symbols);

int compare_symbols(const char *s1, const char *s2);
bool list_is_not_sort(symbol_t *symbols);
symbol_t *sort_symbols(symbol_t *symbols);

#endif /* !PROTOTYPES_H */
