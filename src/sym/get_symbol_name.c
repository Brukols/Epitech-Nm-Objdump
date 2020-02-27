/*
** EPITECH PROJECT, 2020
** sym
** File description:
** getst_info
*/

#include "../../include/elf_struct.h"

char *get_symbol_name(elf_t *elf, size_t index)
{
    return ((elf->sym.sym32 ? &(elf->sym.strtab)[elf->sym.sym32[index].st_name] : \
&(elf->sym.strtab)[elf->sym.sym64[index].st_name]));
}