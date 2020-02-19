/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_objdump_struct
*/

#include "../../include/objdump.h"
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

objdump_t init_objdump_struct(char *path)
{
    objdump_t obj;
    struct stat s;

    obj.path = path;
    obj.fd = open_file(path);
    fstat(obj.fd, &s);
    obj.buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, obj.fd, 0);
    return (obj);
}