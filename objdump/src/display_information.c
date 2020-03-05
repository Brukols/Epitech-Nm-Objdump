/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_information
*/

#include "objdump.h"

static bool is_a(const char *path)
{
    int lgt = strlen(path);

    if (lgt <= 1)
        return (false);
    if (path[lgt - 1] == 'a' && path[lgt - 2] == '.')
        return (true);
    return (false);
}

int display_information(char *path)
{
    objdump_t obj = init_elf_struct(path);

    if (obj.fd == -1)
        return (-1);
    if (obj.buf == (void *)-1) {
        close_file(obj.fd);
        return (FAILURE);
    }
    if (is_a(path)) {
        close_file(obj.fd);
        return (SUCCESS);
    }
    if (init_elfs_struct(&obj) == FAILURE) {
        destroy_elf_struct(obj);
        return (FAILURE);
    }
    display_overall_header(&obj);
    display_sections(&obj);
    destroy_elf_struct(obj);
    return (SUCCESS);
}