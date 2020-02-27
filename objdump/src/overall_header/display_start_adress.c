/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_start_adress
*/

#include "../../include/objdump.h"
#include <stdio.h>

void display_start_adress(objdump_t *obj)
{
    printf("start address 0x%016lx\n\n", obj->ehdr.get_e_entry(obj));
}