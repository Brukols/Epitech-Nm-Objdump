/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_phdr
*/

#include "elf_struct.h"

size_t get_p_paddr(elf_t *this)
{
    return ((this->phdr.phdr32 ? this->phdr.phdr32->p_paddr : \
this->phdr.phdr64->p_paddr));
}