/*
** EPITECH PROJECT, 2020
** elf
** File description:
** init_sym_sturct
*/

#include "../include/elf_struct.h"

static void init_sym(elf_t *elf, int index)
{
    if (elf->ehdr.get_e_ident(elf)[EI_CLASS] == ELFCLASS32) {
        elf->sym.sym64 = NULL;
        elf->sym.sym32 = (Elf32_Sym *)(elf->buf + \
elf->shdr.get_sh_offset(elf, index));
        elf->sym.size = elf->shdr.shdr32[index].sh_size / sizeof(Elf32_Sym);
    } else {
        elf->sym.sym32 = NULL;
        elf->sym.sym64 = (Elf64_Sym *)(elf->buf + \
elf->shdr.get_sh_offset(elf, index));
        elf->sym.size = elf->shdr.shdr64[index].sh_size / sizeof(Elf64_Sym);
    }
}

static void init_functions(elf_t *elf)
{
    elf->sym.get_symbol_name = &get_symbol_name;
    elf->sym.get_st_info = &get_st_info;
    elf->sym.get_st_other = &get_st_other;
    elf->sym.get_st_shndx = &get_st_shndx;
    elf->sym.get_st_name = &get_st_name;
    elf->sym.get_st_size = &get_st_size;
    elf->sym.get_st_value = &get_st_value;
}

void init_sym_struct(elf_t *elf)
{
    const char *name;
    bool has_sym = false;
    bool has_strtab = false;

    for (size_t i = 1; i < elf->ehdr.get_e_shnum(elf); i++) {
        name = elf->shdr.addrstrtable + elf->shdr.get_sh_name(elf, i);
        if (strcmp(name, ".symtab") == 0) {
            init_sym(elf, i);
            has_sym = true;
        } else if (strcmp(name, ".strtab") == 0) {
            elf->sym.strtab = elf->buf + elf->shdr.get_sh_offset(elf, i);
            has_strtab = true;
        }
    }
    if (!has_sym || !has_strtab) {
        elf->sym.sym64 = NULL;
        elf->sym.sym32 = NULL;
        return;
    }
    init_functions(elf);
}