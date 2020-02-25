/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_bytes
*/

#include "../../include/objdump.h"
#include <stdio.h>
#include <ctype.h>

static void display_line_bytes(objdump_t *obj, int index, int *i, size_t *addr)
{
    const unsigned char *string = obj->buf;
    int size = obj->shdr.get_sh_size(obj, index);
    int bytes = 0;
    char buffer[16];

    memset(buffer, 0, 17);
    for (; bytes < 16;) {
        for (int a = 0; a < 4; a++, bytes++, (*i)++, (*addr)++) {
            printf((*i < size ? "%02x" : "  "), \
(*i < size ? string[*addr] & 0xff : '\0'));
            buffer[bytes] = (*i < size ? \
(isprint(string[*addr]) ? string[*addr] : '.') : ' ');
        }
        printf(" ");
    }
    printf(" %s", buffer);
    printf("\n");
}

void display_bytes(objdump_t *obj, int index)
{
    int size = obj->shdr.get_sh_size(obj, index);
    size_t addr = obj->shdr.get_sh_offset(obj, index);

    for (int i = 0; i < size;) {
        printf(" %04lx ", (obj->shdr.get_sh_addr(obj, index) + i));
        display_line_bytes(obj, index, &i, &addr);
    }
}