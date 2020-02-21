/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** d_pages
*/

#include "../../../include/objdump.h"

int flag_d_paged(objdump_t *obj)
{
    if (obj->ehdr->e_phnum > 0)
        return (D_PAGED);
    return (0);
}