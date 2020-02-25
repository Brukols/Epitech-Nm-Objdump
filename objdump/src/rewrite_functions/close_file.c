/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** close_file
*/

#include <unistd.h>
#include <stdio.h>

int close_file(int fd)
{
    if (close(fd) == -1) {
        fprintf(stderr, "Objdump : can't close the file\n");
        return (-1);
    }
    return (0);
}