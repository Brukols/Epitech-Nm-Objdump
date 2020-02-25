/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** good_type
*/

#include "../../include/elf_struct.h"
#include <stdio.h>

bool good_type(elf_t *obj)
{
    if (obj->ehdr->e_type == ET_NONE || obj->ehdr->e_type == ET_CORE)
        return (wrong_type(obj));
    return (true);
}