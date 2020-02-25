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
#include <unistd.h>
#include <stdio.h>

objdump_t path_is_directory(objdump_t obj)
{
    printf("objdump: Warning: '%s' is a directory\n", obj.path);
    close_file(obj.fd);
    obj.fd = -1;
    return (obj);
}

objdump_t init_objdump_struct(char *path)
{
    objdump_t obj;
    struct stat s;

    obj.path = path;
    obj.fd = open_file(path);
    if (obj.fd == -1)
        return (obj);
    if (fstat(obj.fd, &s) == -1)
        return (obj);
    if (S_ISDIR(s.st_mode))
        return (path_is_directory(obj));
    obj.buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, obj.fd, 0);
    return (obj);
}