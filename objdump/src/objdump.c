/*
** EPITECH PROJECT, 2020
** Objdump
** File description:
** objdump
*/

#include "objdump.h"
#include <string.h>

int objdump(int ac, char **av)
{
    bool error = false;
    if (ac == 1) {
        if (display_information("a.out") != SUCCESS)
            error = true;
    }
    for (int i = 1; i < ac; i++) {
        if (display_information(av[i]) != SUCCESS)
            error = true;
    }
    return ((error ? 84 : 0));
}