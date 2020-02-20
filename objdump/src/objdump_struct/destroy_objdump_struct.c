/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** destroy_objdump_struct
*/

#include "../../include/objdump.h"

void destroy_objdump_struct(objdump_t obj)
{
    close_file(obj.fd);
}