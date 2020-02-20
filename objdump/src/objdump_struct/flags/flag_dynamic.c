/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** dynamic
*/

#include "../../../include/objdump.h"

int flag_dynamic(objdump_t *obj)
{
    if (obj->ehdr->e_type == ET_DYN)
        return (DYNAMIC);
    return (0);
}