/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** prototypes
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "objdump.h"

int objdump(int, char **);
int display_information(char *);
int display_overall_header(objdump_t *obj);

/* ERROR */
bool file_has_error(objdump_t *obj);
bool good_ident(objdump_t *obj);
bool good_version(objdump_t *obj);
bool good_type(objdump_t *obj);
bool good_machine(objdump_t *obj);

/* FILE */
int close_file(int);
int open_file(char *);

/* OVERALL HEADER */
void display_file_format(objdump_t *obj);
void display_architecture(objdump_t *obj);
void display_flags(objdump_t *obj);
void display_start_adress(objdump_t *obj);

/* SECTIONS */
int display_sections(objdump_t *obj);
void display_bytes(objdump_t *obj, int index);
const char *printf_string(objdump_t *obj, int index);

#endif /* !PROTOTYPES_H */
