/*
** EPITECH PROJECT, 2020
** Objdump
** File description:
** objdump
*/

#include "../include/objdump.h"
#include <string.h>

int objdump(int ac, char **av)
{
    if (ac == 1)
        display_information("a.out");
    for (int i = 1; i < ac; i++) {
        display_information(av[i]);
    }
    return (0);
}