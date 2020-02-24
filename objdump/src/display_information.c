/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_information
*/

#include "../include/objdump.h"

int display_information(char *path)
{
    objdump_t obj = init_objdump_struct(path);

    if (obj.fd == -1)
        return (-1);
    if (obj.buf == (void *)-1)
        return (close_file(obj.fd));
    if (init_elf_struct(&obj) == FAILURE) {
        destroy_objdump_struct(obj);
        return (FAILURE);
    }
    display_overall_header(&obj);
    display_sections(&obj);
    destroy_objdump_struct(obj);
    return (SUCCESS);
}