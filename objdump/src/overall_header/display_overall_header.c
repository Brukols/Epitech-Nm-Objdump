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
    obj->ehdr = obj->buf;

    if (file_format(obj) == FAILURE)
        return (FAILURE);
    printf("%s\n", obj->ehdr->e_ident);
    printf("%d\n", obj->ehdr->e_machine);
    printf("%d\n", obj->ehdr->e_version);
    printf("%ld\n", obj->ehdr->e_entry);
    printf("%ld\n", obj->ehdr->e_phoff);
    printf("%ld\n", obj->ehdr->e_shoff);
    printf("%d\n", obj->ehdr->e_flags);
    printf("%d\n", obj->ehdr->e_ehsize);
    printf("%d\n", obj->ehdr->e_phentsize);
    printf("%d\n", obj->ehdr->e_phnum);
    printf("%d\n", obj->ehdr->e_shentsize);
    printf("%d\n", obj->ehdr->e_shnum);
    printf("%d\n", obj->ehdr->e_shstrndx);
    return (0);
}