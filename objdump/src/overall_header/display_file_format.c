/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_file_format
*/

#include "../../include/objdump.h"
#include <stdio.h>

void display_file_format(objdump_t *obj)
{
    printf("\n%s:     file format %s\n", obj->path, \
(obj->ehdr.get_e_ident(obj)[4] == ELFCLASS32 ? "elf32-x86-32" : "elf64-x86-64"));
}