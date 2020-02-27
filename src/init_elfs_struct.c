/*
** EPITECH PROJECT, 2020
** sr
** File description:
** nm
*/

#include "../include/elf_struct.h"

int init_elfs_struct(elf_t *obj)
{
    obj->ehdr = obj->buf;
    if (file_has_error(obj)) {
        return (FAILURE);
    }
    init_phdr_struct(obj);
    init_shdr_struct(obj);
    init_sym_struct(obj);
    return (SUCCESS);
}