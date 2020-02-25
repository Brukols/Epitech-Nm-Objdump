/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** dynamic
*/

#include "../../include/elf_struct.h"

int flag_dynamic(elf_t *obj)
{
    if (obj->ehdr->e_type == ET_DYN)
        return (DYNAMIC);
    return (0);
}