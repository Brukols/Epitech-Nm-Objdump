/*
** EPITECH PROJECT, 2020
** nm
** File description:
** print_fileç_truncated
*/

#include "nm.h"
#include <stdio.h>

void print_file_truncated(nm_t *nm)
{
    fprintf(stderr, "nm: %s: file truncated\n", nm->path);
}