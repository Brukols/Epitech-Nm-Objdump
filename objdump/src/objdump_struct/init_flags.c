/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_flags
*/

#include "../../include/objdump.h"
#include <string.h>
#include <stdio.h>

void init_flags(objdump_t *obj)
{
    obj->flags = 0;
    int (*funcs[])(objdump_t *) = {
        flag_has_reloc, flag_exec_p, flag_has_lineno, flag_has_debug,
        flag_has_syms, flag_has_locals, flag_dynamic, flag_wp_text,
        flag_d_paged, NULL
    };

    for (size_t i = 0; funcs[i]; i++) {
        obj->flags += funcs[i](obj);
    }
}