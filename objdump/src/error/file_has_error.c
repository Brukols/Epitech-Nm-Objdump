/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** file_has_error
*/

#include "../../include/objdump.h"
#include <string.h>

bool file_has_error(objdump_t *obj)
{
    bool (*funcs[])(objdump_t *) = {
        good_ident, good_type, good_machine, good_version, NULL
    };
    for (size_t i = 0; funcs[i]; i++) {
        if (funcs[i](obj) == false)
            return (true);
    }
    return (false);
}