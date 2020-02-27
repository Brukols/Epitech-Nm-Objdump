/*
** EPITECH PROJECT, 2020
** elf
** File description:
** init_ehdr_struct
*/

#include "../include/elf_struct.h"

void init_ehdr_struct(elf_t *elf)
{
    if (elf->ehdr.ehdr64->e_ident[EI_CLASS] == ELFCLASS32) {
        elf->ehdr.ehdr32 = elf->buf;
        elf->ehdr.ehdr64 = NULL;
    } else
        elf->ehdr.ehdr32 = NULL;
    elf->ehdr.get_e_ehsize = &get_e_ehsize;
    elf->ehdr.get_e_entry = &get_e_entry;
    elf->ehdr.get_e_flags = &get_e_flags;
    elf->ehdr.get_e_ident = &get_e_ident;
    elf->ehdr.get_e_machine = &get_e_machine;
    elf->ehdr.get_e_phentsize = &get_e_phentsize;
    elf->ehdr.get_e_phnum = &get_e_phnum;
    elf->ehdr.get_e_phoff = &get_e_phoff;
    elf->ehdr.get_e_shentsize = &get_e_shentsize;
    elf->ehdr.get_e_shnum = &get_e_shnum;
    elf->ehdr.get_e_shoff = &get_e_shoff;
    elf->ehdr.get_e_shstrndx = &get_e_shstrndx;
    elf->ehdr.get_e_type = &get_e_type;
    elf->ehdr.get_e_version = &get_e_version;
}