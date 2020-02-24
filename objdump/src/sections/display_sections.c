/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_sectioins
*/

#include "../../include/objdump.h"
#include <stdio.h>

static void display_line_bytes(objdump_t *obj, int index, int *i, int *offset)
{
    const char *string = obj->buf;
    int size = obj->shdr.get_sh_size(obj, index);

    for (int b = 0; b < 16 && *i < size; (*i)++) {
        for (int a = 0; *i < size && a != 4; a++, b++) {
            printf("%x", string[*offset]);
        }
        if (*i < size)
            break;
        printf(" ");
    }
}

static void display_bytes(objdump_t *obj, int index)
{
    int size = obj->shdr.get_sh_size(obj, index);
    int offset = obj->shdr.get_sh_offset(obj, index);

    for (int i = 0; i < size; i++) {
        printf(" %06lx", obj->shdr.get_sh_addr(obj, index) + i);
        display_line_bytes(obj, index, &i, &offset);
    }
    printf("\n");
}

int display_sections(objdump_t *obj)
{
    const char *name;

    for (size_t i = 1; i < obj->ehdr->e_shnum; i++) {
        name = obj->shdr.addrstrtable + obj->shdr.get_sh_name(obj, i);
        printf("Content of section %s:\n", name);
        display_bytes(obj, i);
        return (SUCCESS);
    }
    return (SUCCESS);
}