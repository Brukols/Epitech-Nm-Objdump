/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_information
*/

#include "../include/objdump.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Objdump : can't open file\n");
    }
    return (fd);
}

int close_file(int fd)
{
    if (close(fd) == -1) {
        fprintf(stderr, "Objdump : can't close the file\n");
        return (-1);
    }
    return (0);
}

objdump_t init_objdump_struct(char *path)
{
    objdump_t obj;

    obj.path = path;
    return (obj);
}

int display_information(char *path)
{
    struct stat s;
    objdump_t obj = init_objdump_struct(path);

    obj.fd = open_file(path);
    if (obj.fd == -1)
        return (-1);
    fstat(obj.fd, &s);
    obj.buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, obj.fd, 0);
    if (obj.buf == (void *)-1)
        return (close_file(obj.fd));
    display_overall_header(&obj);
    //display_full_content(fd, path);
    return (close_file(obj.fd));
}