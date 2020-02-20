/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_flags
*/

#include "../../include/objdump.h"
#include <stdio.h>

typedef struct flags_s
{
    int flags;
    char *name;
} flags_t;

const flags_t flags[] = {
    {D_PAGED, "D_PAGED"},
    {WP_TEXT, "WP_TEXT"},
    {DYNAMIC, "DYNAMIC"},
    {HAS_LOCALS, "HAS_LOCALS"},
    {HAS_SYMS, "HAS_SYMS"},
    {HAS_DEBUG, "HAS_DEBUG"},
    {HAS_LINENO, "HAS_LINENO"},
    {EXEC_P, "EXEC_P"},
    {HAS_RELOC, "HAS_RELOC"}
};

void display_flags(objdump_t *obj)
{
    int tmp_flags = 0;
    bool has_flags = false;

    init_flags(obj);
    printf("flags 0x%08x:\n", obj->flags);
    tmp_flags = obj->flags;
    for (size_t i = 0; i < 9; i++) {
        if (tmp_flags - flags[i].flags >= 0) {
            tmp_flags -= flags[i].flags;
            printf((has_flags ? ", %s" : "%s"), flags[i].name);
            has_flags = true;
        }
    }
    printf("\n");
}