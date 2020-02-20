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
void init_elf_struct(objdump_t *obj);

/* ERROR */
bool file_has_error(objdump_t *obj);
bool good_ident(objdump_t *obj);
bool good_version(objdump_t *obj);
bool good_type(objdump_t *obj);
bool good_machine(objdump_t *obj);

/* FILE */
int close_file(int);
int open_file(char *);

/* OBJDUMP STRUCT */
objdump_t init_objdump_struct(char *);
void destroy_objdump_struct(objdump_t obj);

/* OVERALL HEADER */
void display_file_format(objdump_t *obj);
void display_architecture(objdump_t *obj);

#endif /* !OBJDUMP_H */
