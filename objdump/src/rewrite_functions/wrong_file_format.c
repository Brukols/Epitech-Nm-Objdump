/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** wrong_file_format
*/

#include "objdump.h"
#include <stdio.h>

bool wrong_file_format(objdump_t *obj)
{
    fprintf(stderr, "objdump: %s: file format not recognized\n", obj->path);
    return (false);
}