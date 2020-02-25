/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_phdr
*/

#include "../../../include/objdump.h"

size_t get_p_align(objdump_t *this)
{
    return ((this->phdr.phdr32 ? this->phdr.phdr32->p_align : \
this->phdr.phdr64->p_align));
}