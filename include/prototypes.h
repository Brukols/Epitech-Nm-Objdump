/*
** EPITECH PROJECT, 2020
** elf
** File description:
** protoypes
*/

#ifndef PROTOTYPES_ELF_H
#define PROTOTYPES_ELF_H

#include "elf_struct.h"

/* OBJDUMP STRUCT */
elf_t init_objdump_struct(char *);
void destroy_objdump_struct(elf_t obj);
void init_flags(elf_t *obj);
void init_phdr_struct(elf_t *obj);
void init_shdr_struct(elf_t *obj);

/* ERROR */
bool good_ident(elf_t *obj);
bool good_type(elf_t *obj);
bool good_version(elf_t *obj);

/* FLAGS */
bool file_has_error(elf_t *obj);
int flag_has_reloc(elf_t *obj);
int flag_exec_p(elf_t *obj);
int flag_has_lineno(elf_t *obj);
int flag_has_locals(elf_t *obj);
int flag_has_debug(elf_t *obj);
int flag_wp_text(elf_t *obj);
int flag_has_syms(elf_t *obj);
int flag_dynamic(elf_t *obj);
int flag_d_paged(elf_t *obj);

/* FUNCTION TO RE WRITE */
int open_file(char *path);
int close_file(int fd);
bool wrong_file_format(elf_t *obj);
elf_t path_is_directory(elf_t obj);
bool wrong_type(elf_t *obj);

#endif /* !PROTOTYPES_H */
