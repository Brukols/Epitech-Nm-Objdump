/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_bytes
*/

#include "../../include/objdump.h"
#include <stdio.h>
#include <ctype.h>

static void print_empty_bytes(int b, int bytes)
{
    while (bytes < 16) {
        for (size_t i = 0; i < 4 && bytes < 16; i++, bytes++) {
            printf("  ");
        }
        if (bytes != 16)
            printf(" ");
    }
}

static size_t compute_size(objdump_t *obj, int index)
{
    size_t size = obj->shdr.get_sh_size(obj, index);
    size_t addralign = obj->shdr.get_sh_addralign(obj, index);

    if (addralign == 0 && addralign == 1) {

    }
    return (size);
}

static void display_line_bytes(objdump_t *obj, int index, int *i, size_t *addr)
{
    const unsigned char *string = obj->buf;
    int size = compute_size(obj, index);
    int bytes = 0;
    char buffer[16];

    // printf("%ld\n", obj->shdr.get_sh_addralign(obj, index));
    memset(buffer, 0, 17);
    for (; bytes < 16 && *i < size;) {
        for (int a = 0; a < 4 && *i < size; a++, bytes++, (*i)++, (*addr)++) {
            printf("%02x", (string[*addr]) & 0xff);
            buffer[bytes] = (isprint(string[*addr]) ? string[*addr] : '.');
        }
        printf(" ");
        if (*i == size)
            break;
    }
    if (bytes < 16)
        print_empty_bytes(*i, bytes);
    printf(" %s", buffer);
    printf("\n");
}

void display_bytes(objdump_t *obj, int index)
{
    int size = obj->shdr.get_sh_size(obj, index);
    size_t addr = obj->shdr.get_sh_offset(obj, index);

    // printf("Addralign : %ld\n", obj->shdr.get_sh_addralign(obj, index));
    // printf("Size : %ld\n", obj->shdr.get_sh_size(obj, index));
    // printf("Entsize : %ld\n", obj->shdr.get_sh_entsize(obj, index));
    for (int i = 0; i < size;) {
        printf(" %04lx ", (obj->shdr.get_sh_addr(obj, index) + i - (i / 16)));
        display_line_bytes(obj, index, &i, &addr);
    }
}