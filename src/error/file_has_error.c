/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** file_has_error
*/

#include "elf_struct.h"
#include <string.h>
#include <stdbool.h>

bool file_has_error(elf_t *obj)
{
    bool (*funcs[])(elf_t *) = {
        good_ident, good_type, good_version, NULL
    };
    for (size_t i = 0; funcs[i]; i++) {
        if (funcs[i](obj) == false)
            return (true);
    }
    return (false);
}