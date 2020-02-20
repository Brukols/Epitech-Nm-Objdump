/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_sh
*/

#include "../../../include/objdump.h"

size_t get_sh_entsize(objdump_t *this)
{
    return ((this->shdr.shdr32 ? this->shdr.shdr32->sh_entsize : \
this->shdr.shdr64->sh_entsize));
}