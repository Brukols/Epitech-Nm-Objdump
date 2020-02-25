/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_sh
*/

#include "../../../include/objdump.h"

size_t get_sh_info(objdump_t *this, size_t index)
{
    return ((this->shdr.shdr32 ? this->shdr.shdr32[index].sh_info : \
this->shdr.shdr64[index].sh_info));
}