/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_elf_struct
*/

#include "../../include/objdump.h"

void init_elf_struct(objdump_t *obj)
{
    obj->ehdr = obj->buf;
}