/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_architecture
*/

#include "../../include/objdump.h"
#include <stdio.h>

typedef struct architecture_s
{
    int define;
    char *name;
} architecture_t;

const architecture_t architecture[] = {
    {EM_M32, "m32"},
    {EM_SPARC, "sparc"},
    {EM_386, "386"},
    {EM_68K, "68k"},
    {EM_88K, "88k"},
    {EM_860, "860"},
    {EM_MIPS, "mips"},
    {EM_PARISC, "parisc"},
    {EM_SPARC32PLUS, "sparc32plus"},
    {EM_PPC, "ppc"},
    {EM_PPC64, "ppc64"},
    {EM_S390, "s390"},
    {EM_ARM, "arm"},
    {EM_SH, "sh"},
    {EM_SPARCV9, "sparcv9"},
    {EM_IA_64, "ia-69"},
    {EM_X86_64, "x86-64"},
    {EM_VAX, "vax"}
};

void display_architecture(objdump_t *obj)
{
    for (size_t i = 0; i < 18; i++) {
        if (obj->ehdr->e_machine == architecture[i].define) {
            printf("architecture: i386:%s, ", architecture[i].name);
        }
    }
}