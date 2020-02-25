/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** pth_is_directory
*/

#include "../../include/nm.h"
#include <stdio.h>

nm_t path_is_directory(nm_t obj)
{
    printf("nm: Warning: '%s' is a directory\n", obj.path);
    close_file(obj.fd);
    obj.fd = -1;
    return (obj);
}