/*
** EPITECH PROJECT, 2020
** elf
** File description:
** truncated
*/

#include "elf_struct.h"
#include <stdio.h>

bool file_truncated(elf_t *obj)
{
    size_t size = obj->ehdr.get_e_shoff(obj);

    size += (obj->ehdr.get_e_shnum(obj) * obj->ehdr.get_e_shentsize(obj));
    if (size > obj->size) {
        print_file_truncated(obj);
        return (true);
    }
    return (false);
}