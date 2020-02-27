/*
** EPITECH PROJECT, 2020
** nm
** File description:
** compare symbolks
*/

#include <string.h>
#include <ctype.h>

static void incr_i(size_t *i, const char *s)
{
    for (; s[*i] && !isalnum(s[*i]); (*i)++);
}

int compare_symbols(const char *s1, const char *s2)
{
    size_t i_s1 = 0;
    size_t i_s2 = 0;

    while (s1[i_s1]) {
        incr_i(&i_s1, s1);
        incr_i(&i_s2, s2);
        if (tolower(s1[i_s1]) < tolower(s2[i_s2]))
            return (-1);
        if (tolower(s1[i_s1]) > tolower(s2[i_s2]))
            return (1);
        if (s1[i_s1])
            i_s1++;
        if (s2[i_s2])
            i_s2++;
    }
    return (0);
}