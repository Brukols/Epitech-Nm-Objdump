/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** wrong_file_format
*/

#include "../../include/nm.h"
#include <stdio.h>

bool wrong_file_format(nm_t *obj)
{
    fprintf(stderr, "nm: %s: file format not recognized\n", obj->path);
    return (false);
}