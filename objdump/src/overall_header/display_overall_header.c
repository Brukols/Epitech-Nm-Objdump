/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_information
*/

#include "../../include/objdump.h"
#include <stdio.h>
#include <elf.h>

int display_overall_header(objdump_t *obj)
{
    display_file_format(obj);
    display_architecture(obj);
    display_flags(obj);
    display_start_adress(obj);
    return (0);
}