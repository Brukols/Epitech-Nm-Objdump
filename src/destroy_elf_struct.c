/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** destroy_objdump_struct
*/

#include "elf_struct.h"

void destroy_elf_struct(elf_t obj)
{
    close_file(obj.fd);
}