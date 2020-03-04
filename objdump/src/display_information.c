/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_information
*/

#include "objdump.h"

int display_information(char *path)
{
    objdump_t obj = init_elf_struct(path);

    if (obj.fd == -1)
        return (-1);
    if (obj.buf == (void *)-1) {
        close_file(obj.fd);
        return (FAILURE);
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