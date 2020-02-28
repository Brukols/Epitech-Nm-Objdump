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
int display_informations(int ac, char *path);

void display_symbols(nm_t *nm);
symbol_t *init_symbols(nm_t *nm);
void free_symbols(symbol_t *symbols);

int compare_symbols(const char *s1, const char *s2);
bool list_is_not_sort(symbol_t *symbols);
symbol_t *sort_symbols(symbol_t *symbols);

// LETTERS
bool is_maj_a(nm_t *nm, int i);
bool is_min_a(nm_t *nm, int i);
bool is_maj_b(nm_t *nm, int i);
bool is_min_b(nm_t *nm, int i);
bool is_maj_c(nm_t *nm, int i);
bool is_min_c(nm_t *nm, int i);
bool is_maj_d(nm_t *nm, int i);
bool is_min_d(nm_t *nm, int i);
bool is_maj_r(nm_t *nm, int i);
bool is_min_r(nm_t *nm, int i);
bool is_maj_t(nm_t *nm, int i);
bool is_min_t(nm_t *nm, int i);
bool is_maj_u(nm_t *nm, int i);
bool is_min_u(nm_t *nm, int i);
bool is_maj_v(nm_t *nm, int i);
bool is_min_v(nm_t *nm, int i);
bool is_maj_w(nm_t *nm, int i);
bool is_min_w(nm_t *nm, int i);

#endif /* !PROTOTYPES_H */
