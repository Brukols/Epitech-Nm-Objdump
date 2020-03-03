/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_phdr_struct
*/

#include "elf_struct.h"

void init_phdr_struct(elf_t *obj)
{
    if (obj->ehdr.get_e_ident(obj)[EI_CLASS] == ELFCLASS32) {
        obj->phdr.phdr64 = NULL;
        obj->phdr.phdr32 = obj->buf + (obj->ehdr.get_e_phoff(obj));
    } else {
        obj->phdr.phdr64 = obj->buf + (obj->ehdr.get_e_phoff(obj));
        obj->phdr.phdr32 = NULL;
    }
    obj->phdr.get_p_align = &get_p_align;
    obj->phdr.get_p_filesz = &get_p_filesz;
    obj->phdr.get_p_flags = &get_p_flags;
    obj->phdr.get_p_memsz = &get_p_memsz;
    obj->phdr.get_p_offset = &get_p_offset;
    obj->phdr.get_p_paddr = &get_p_paddr;
    obj->phdr.get_p_type = &get_p_type;
    obj->phdr.get_p_vaddr = &get_p_vaddr;
}