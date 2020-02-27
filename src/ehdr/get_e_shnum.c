/*
** EPITECH PROJECT, 2020
** elf
** File description:
** get_e_shnum
*/

#include "../../include/elf_struct.h"

size_t get_e_shnum(elf_t *elf)
{
    return ((elf->ehdr.ehdr32 ? elf->ehdr.ehdr32->e_shnum : \
elf->ehdr.ehdr64->e_shnum));
}