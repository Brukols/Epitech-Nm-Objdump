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

int display_information(char *path)
{
    objdump_t obj = init_objdump_struct(path);

    if (obj.fd == -1)
        return (-1);
    if (obj.buf == (void *)-1)
        return (close_file(obj.fd));
    display_overall_header(&obj);
    //display_full_content(fd, path);
    return (close_file(obj.fd));
}