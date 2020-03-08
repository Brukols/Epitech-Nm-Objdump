/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** open_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "nm: '%s': No such file\n", path);
    }
    return (fd);
}