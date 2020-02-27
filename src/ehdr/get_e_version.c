/*
** EPITECH PROJECT, 2020
** elf
** File description:
** get_e_version
*/

#include "../../include/elf_struct.h"

size_t get_e_version(elf_t *elf)
{
    return ((elf->ehdr.ehdr32 ? elf->ehdr.ehdr32->e_version : \
elf->ehdr.ehdr64->e_version));
}