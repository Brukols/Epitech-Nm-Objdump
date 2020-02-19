/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** file_format
*/

#include "../../include/objdump.h"

int file_format(objdump_t *obj)
{
    if (!is_elf(obj)) {
        return (FAILURE);
    }
    return (SUCCESS);
}
