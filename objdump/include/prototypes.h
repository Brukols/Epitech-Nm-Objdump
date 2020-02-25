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
int init_elf_struct(objdump_t *obj);

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
void init_flags(objdump_t *obj);
void init_phdr_struct(objdump_t *obj);
void init_shdr_struct(objdump_t *obj);

/* FLAGS */
int flag_has_reloc(objdump_t *obj);
int flag_exec_p(objdump_t *obj);
int flag_has_lineno(objdump_t *obj);
int flag_has_locals(objdump_t *obj);
int flag_has_debug(objdump_t *obj);
int flag_wp_text(objdump_t *obj);
int flag_has_syms(objdump_t *obj);
int flag_dynamic(objdump_t *obj);
int flag_d_paged(objdump_t *obj);

/* OVERALL HEADER */
void display_file_format(objdump_t *obj);
void display_architecture(objdump_t *obj);
void display_flags(objdump_t *obj);
void display_start_adress(objdump_t *obj);

/* SECTIONS */
int display_sections(objdump_t *obj);
void display_bytes(objdump_t *obj, int index);

#endif /* !PROTOTYPES_H */
