/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** d_pages
*/

#include "../../include/elf_struct.h"

int flag_d_paged(elf_t *obj)
{
    if (obj->ehdr.get_e_phnum(obj) > 0)
        return (D_PAGED);
    return (0);
}