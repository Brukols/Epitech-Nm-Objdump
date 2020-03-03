/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_shdr_struct
*/

#include "elf_struct.h"

void init_shdr_struct(elf_t *obj)
{
    if (obj->ehdr.get_e_ident(obj)[EI_CLASS] == ELFCLASS32) {
        obj->shdr.shdr64 = NULL;
        obj->shdr.shdr32 = obj->buf + (obj->ehdr.get_e_shoff(obj));
    } else {
        obj->shdr.shdr64 = obj->buf + (obj->ehdr.get_e_shoff(obj));
        obj->shdr.shdr32 = NULL;
    }
    obj->shdr.get_sh_addr = &get_sh_addr;
    obj->shdr.get_sh_addralign = &get_sh_addralign;
    obj->shdr.get_sh_entsize = &get_sh_entsize;
    obj->shdr.get_sh_flags = &get_sh_flags;
    obj->shdr.get_sh_info = &get_sh_info;
    obj->shdr.get_sh_link = &get_sh_link;
    obj->shdr.get_sh_name = &get_sh_name;
    obj->shdr.get_sh_offset = &get_sh_offset;
    obj->shdr.get_sh_size = &get_sh_size;
    obj->shdr.get_sh_type = &get_sh_type;
    obj->shdr.addrstrtable = obj->buf + obj->shdr.get_sh_offset(obj, \
obj->ehdr.get_e_shstrndx(obj));
}