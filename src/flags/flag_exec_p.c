/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** flag_exec_p
*/

#include "../../include/elf_struct.h"

int flag_exec_p(elf_t *obj)
{
    if (obj->ehdr->e_type == ET_EXEC)
        return (EXEC_P);
    return (0);
}