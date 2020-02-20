/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_exec_p
*/

#include "../../../include/objdump.h"

int flag_exec_p(objdump_t *obj)
{
    if (obj->ehdr->e_type == ET_EXEC)
        return (EXEC_P);
    return (0);
}