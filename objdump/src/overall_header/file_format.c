/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** file_format
*/

#include "../../include/objdump.h"
#include <stdio.h>

int file_format(objdump_t *obj)
{
    printf("\n%s:\tfile format elf64-x86-64\n", obj->path);
    return (SUCCESS);
}
