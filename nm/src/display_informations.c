/*
** EPITECH PROJECT, 2020
** nm
** File description:
** display_informations
*/

#include "nm.h"
#include <stdio.h>

int display_informations(int ac, char *path)
{
    nm_t nm = init_elf_struct(path);

    if (nm.fd == -1)
        return (-1);
    if (nm.buf == (void *)-1)
        return (close_file(nm.fd));
    if (init_elfs_struct(&nm) == FAILURE) {
        destroy_elf_struct(nm);
        return (FAILURE);
    }
    if (ac > 2)
        printf("\n%s:\n", path);
    if (!nm.sym.sym32 && !nm.sym.sym64)
        printf("nm: %s: no symbols\n", nm.path);
    else
        display_symbols(&nm);
    destroy_elf_struct(nm);
    return (SUCCESS);
}