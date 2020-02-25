/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_phdr
*/

#include "../../include/elf_struct.h"

size_t get_p_memsz(elf_t *this)
{
    return ((this->phdr.phdr32 ? this->phdr.phdr32->p_memsz : \
this->phdr.phdr64->p_memsz));
}