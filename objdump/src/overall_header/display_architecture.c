/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** display_architecture
*/

#include "../../include/objdump.h"
#include <stdio.h>

const char defines[] = {
    EM_M32, EM_SPARC, EM_386, EM_68K, EM_88K, EM_860, EM_MIPS, EM_PARISC, \
    EM_SPARC32PLUS, EM_PPC, EM_PPC64, EM_S390, EM_ARM, EM_SH, EM_SPARCV9, \
    EM_IA_64, EM_X86_64, EM_VAX
};

const char *architectures[] = {
    "m32", "sparc", "386", "68k", "88k", "860", "mips", "parisc", \
    "sparc32plus", "ppc", "ppc64", "s390", "arm", "sh", "sparcv9", \
    "ia_64", "x86-64", "vax", NULL
};

void display_architecture(objdump_t *obj)
{
    for (size_t i = 0; architectures[i]; i++) {
        if (obj->ehdr->e_machine == defines[i]) {
            printf("architecture: i386:%s, ", architectures[i]);
        }
    }
}