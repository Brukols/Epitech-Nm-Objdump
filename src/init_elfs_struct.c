/*
** EPITECH PROJECT, 2020
** sr
** File description:
** nm
*/

#include "elf_struct.h"

int init_elfs_struct(elf_t *obj)
{
    obj->ehdr.ehdr64 = obj->buf;
    if (file_has_error(obj)) {
        return (FAILURE);
    }
    init_ehdr_struct(obj);
    init_phdr_struct(obj);
    init_shdr_struct(obj);
    init_sym_struct(obj);
    if (file_truncated(obj))
        return (FAILURE);
    return (SUCCESS);
}