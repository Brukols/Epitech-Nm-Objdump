/*
** EPITECH PROJECT, 2020
** utility
** File description:
** header
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <string.h>

typedef struct printf_string_s
{
    size_t nb;
    const char *str;
} printf_string_t;

typedef struct architecture_s
{
    size_t define;
    char *name;
} architecture_t;

typedef struct flags_s
{
    int flags;
    char *name;
} flags_t;

#endif /* !UTILITY_H */
