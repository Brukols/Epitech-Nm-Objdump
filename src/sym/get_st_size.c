/*
** EPITECH PROJECT, 2020
** sym
** File description:
** getst_size
*/

#include "../../include/elf_struct.h"

size_t get_st_size(elf_t *elf, size_t index)
{
    return ((elf->sym.sym32 ? elf->sym.sym32[index].st_size : \
elf->sym.sym64[index].st_size));
}