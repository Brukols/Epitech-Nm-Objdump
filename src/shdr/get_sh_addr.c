/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_sh
*/

#include "elf_struct.h"

size_t get_sh_addr(elf_t *this, size_t index)
{
    return ((this->shdr.shdr32 ? this->shdr.shdr32[index].sh_addr : \
this->shdr.shdr64[index].sh_addr));
}