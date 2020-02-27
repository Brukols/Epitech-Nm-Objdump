/*
** EPITECH PROJECT, 2020
** elf
** File description:
** get_e_shstrndx
*/

#include "../../include/elf_struct.h"

size_t get_e_shstrndx(elf_t *elf)
{
    return ((elf->ehdr.ehdr32 ? elf->ehdr.ehdr32->e_shstrndx : \
elf->ehdr.ehdr64->e_shstrndx));
}