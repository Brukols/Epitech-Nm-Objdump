/*
** EPITECH PROJECT, 2020
** sym
** File description:
** getst_name
*/

#include "../../include/elf_struct.h"

size_t get_st_name(elf_t *elf, size_t index)
{
    return ((elf->sym.sym32 ? elf->sym.sym32[index].st_name : \
elf->sym.sym64[index].st_name));
}