/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** pth_is_directory
*/

#include "objdump.h"
#include <stdio.h>

objdump_t path_is_directory(objdump_t obj)
{
    printf("objdump: Warning: '%s' is a directory\n", obj.path);
    close_file(obj.fd);
    obj.fd = -1;
    return (obj);
}