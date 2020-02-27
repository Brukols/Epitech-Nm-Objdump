/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_exec_p
*/

#include "../../include/elf_struct.h"

int flag_exec_p(elf_t *obj)
{
    if (obj->ehdr.get_e_type(obj) == ET_EXEC)
        return (EXEC_P);
    return (0);
}