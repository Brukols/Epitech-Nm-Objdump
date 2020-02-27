/*
** EPITECH PROJECT, 2020
** sym
** File description:
** getst_info
*/

#include "../../include/elf_struct.h"

size_t get_st_info(elf_t *elf, size_t index)
{
    return ((elf->sym.sym32 ? elf->sym.sym32[index].st_info : \
elf->sym.sym64[index].st_info));
}