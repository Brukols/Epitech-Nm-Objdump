/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_sh
*/

#include "../../../include/objdump.h"

size_t get_sh_flags(objdump_t *this)
{
    return ((this->shdr.shdr32 ? this->shdr.shdr32->sh_flags : \
this->shdr.shdr64->sh_flags));
}