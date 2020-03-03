/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_flags
*/

#include "objdump.h"
#include "utility.h"
#include <stdio.h>

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

void dump_flags(int *flags_index, int last_i)
{
    bool first = true;

    last_i--;
    for (; last_i >= 0; last_i--) {
        printf((first ? "%s" : ", %s"), flags[flags_index[last_i]].name);
        first = false;
    }
    printf("\n");
}

void display_flags(objdump_t *obj)
{
    int tmp_flags = 0;
    int i_flags_index = false;
    int flags_index[9];

    memset(flags_index, -1, 10);
    init_flags(obj);
    printf("flags 0x%08x:\n", obj->flags);
    tmp_flags = obj->flags;
    for (size_t i = 0; i < 9; i++) {
        if (tmp_flags - flags[i].flags >= 0) {
            tmp_flags -= flags[i].flags;
            flags_index[i_flags_index] = i;
            i_flags_index++;
        }
    }
    dump_flags(flags_index, i_flags_index);
}