/*
** EPITECH PROJECT, 2020
** nm
** File description:
** nm
*/

#include "../include/nm.h"

int nm(int ac, char **av)
{
    bool error = false;

    if (ac == 1) {
        if (display_informations("a.out") != SUCCESS)
            error = true;
    }
    for (int i = 1; i < ac; i++) {
        if (display_informations(av[i]) != SUCCESS)
            error = true;
    }
    return ((error ? 84 : 0));
}