/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_shdr_struct
*/

#include "../../include/objdump.h"

void init_shdr_struct(objdump_t *obj)
{
    if (obj->ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
        obj->shdr.shdr64 = NULL;
        obj->shdr.shdr32 = obj->buf + (obj->ehdr->e_shoff);
    } else {
        obj->shdr.shdr64 = obj->buf + (obj->ehdr->e_shoff);
        obj->shdr.shdr32 = NULL;
    }
    obj->shdr.addrstrtable = (obj->shdr.shdr64 ? obj->buf + \
obj->shdr.shdr64[obj->ehdr->e_shstrndx].sh_offset : obj->buf + \
obj->shdr.shdr32[obj->ehdr->e_shstrndx].sh_offset);
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
}