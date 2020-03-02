/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** printf_string
*/

#include "../../include/objdump.h"
#include "../../include/utility.h"

const printf_string_t printf_strings[] = {
    {0xf, " %04lx "},
    {0xff, " %04lx "},
    {0xfff, " %04lx "},
    {0xffff, " %04lx "},
    {0xfffff, " %05lx "},
    {0xffffff, " %06lx "},
    {0xfffffff, " %07lx "},
    {0xffffffff, " %08lx "},
    {0xfffffffff, " %09lx "},
};

const char *printf_string(objdump_t *obj, int index)
{
    int size = obj->shdr.get_sh_size(obj, index);
    size_t addr = obj->shdr.get_sh_addr(obj, index);

    for (size_t i = 0; i < 9; i++) {
        if (size + addr < printf_strings[i].nb)
            return (printf_strings[i].str);
    }
    return (NULL);
}