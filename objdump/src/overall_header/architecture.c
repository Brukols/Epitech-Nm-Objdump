/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** arhcitecutre
*/

#include "../../include/objdump.h"
#include <stdio.h>

int architecture(objdump_t *obj)
{
    if (obj->ehdr->e_machine != EM_X86_64) {
        fprintf(stderr, "objdump: %s: wrong architecture\n", obj->path);
        return (FAILURE);
    }
    printf("architecture: i386:x86-64,");
    return (SUCCESS);
}