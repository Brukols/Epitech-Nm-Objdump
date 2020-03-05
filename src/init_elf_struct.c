/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** init_objdump_struct
*/

#include "elf_struct.h"
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

elf_t init_elf_struct(char *path)
{
    elf_t obj;
    struct stat s;

    obj.path = path;
    obj.buf = (void *)-1;
    obj.fd = open_file(path);
    if (obj.fd == -1)
        return (obj);
    if (fstat(obj.fd, &s) == -1)
        return (obj);
    if (S_ISDIR(s.st_mode))
        return (path_is_directory(obj));
    if (s.st_size == 0)
        return (obj);
    obj.size = s.st_size;
    obj.buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, obj.fd, 0);
    return (obj);
}