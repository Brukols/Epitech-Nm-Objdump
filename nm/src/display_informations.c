/*
** EPITECH PROJECT, 2020
** nm
** File description:
** display_informations
*/

#include "nm.h"
#include <stdio.h>

static bool is_a(const char *path)
{
    int lgt = strlen(path);

    if (lgt <= 1)
        return (false);
    if (path[lgt - 1] == 'a' && path[lgt - 2] == '.')
        return (true);
    return (false);
}

int display_informations(int ac, char *path)
{
    nm_t nm = init_elf_struct(path);

    if (nm.fd == -1)
        return (-1);
    if (nm.buf == (void *)-1) {
        close_file(nm.fd);
        return (FAILURE);
    }
    if (is_a(path))
        return (close_file(nm.fd));
    if (init_elfs_struct(&nm) == FAILURE) {
        destroy_elf_struct(nm);
        return (FAILURE);
    }
    if (ac > 2)
        printf("\n%s:\n", path);
    (!nm.sym.sym32 && !nm.sym.sym64 ? printf("nm: %s: no symbols\n", nm.path) \
: display_symbols(&nm));
    destroy_elf_struct(nm);
    return (SUCCESS);
}