/*
** EPITECH PROJECT, 2020
** sym
** File description:
** getst_shndx
*/

#include "../../include/elf_struct.h"

size_t get_st_shndx(elf_t *elf, size_t index)
{
    return ((elf->sym.sym32 ? elf->sym.sym32[index].st_shndx : \
elf->sym.sym64[index].st_shndx));
}