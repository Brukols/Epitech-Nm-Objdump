/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** objdump?h
*/

#ifndef OBJDUMP_H
#define OBJDUMP_H

#include <elf.h>
#include "macros.h"
#include <stdbool.h>

typedef struct objdump_s
{
    int fd;
    void *buf;
    char *path;
    Elf64_Ehdr *ehdr;
} objdump_t;


int objdump(int, char **);
int display_information(char *);
int display_overall_header(objdump_t *obj);

/* FILE */
int close_file(int);
int open_file(char *);

/* OBJDUMP STRUCT */
objdump_t init_objdump_struct(char *);

/* OVERALL HEADER */
int file_format(objdump_t *obj);
bool is_elf(objdump_t *obj);

#endif /* !OBJDUMP_H */
