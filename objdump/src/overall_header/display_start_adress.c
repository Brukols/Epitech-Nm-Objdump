/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_start_adress
*/

#include "objdump.h"
#include <stdio.h>

void display_start_adress(objdump_t *obj)
{
    if (obj->ehdr.get_e_ident(obj)[EI_CLASS] == ELFCLASS32)
        printf("start address 0x%08lx\n\n", obj->ehdr.get_e_entry(obj));
    else {
        printf("start address 0x%016lx\n\n", obj->ehdr.get_e_entry(obj));
    }
}