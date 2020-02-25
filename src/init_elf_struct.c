/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_elf_struct
*/

#include "../include/elf_struct.h"

int init_elf_struct(elf_t *obj)
{
    obj->ehdr = obj->buf;
    if (file_has_error(obj)) {
        return (FAILURE);
    }
    init_phdr_struct(obj);
    init_shdr_struct(obj);
    return (SUCCESS);
}