/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** print_file_truncated
*/

#include "objdump.h"
#include <stdio.h>

void print_file_truncated(objdump_t *nm)
{
    fprintf(stderr, "objdump: %s: file truncated\n", nm->path);
}