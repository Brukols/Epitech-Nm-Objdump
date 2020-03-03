/*
** EPITECH PROJECT, 2020
** elf
** File description:
** get_e_ident
*/

#include "elf_struct.h"

unsigned char *get_e_ident(elf_t *elf)
{
    return ((elf->ehdr.ehdr32 ? elf->ehdr.ehdr32->e_ident : \
elf->ehdr.ehdr64->e_ident));
}