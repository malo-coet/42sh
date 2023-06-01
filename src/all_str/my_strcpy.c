/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strcpy.c
*/

#include "my.h"
#include "struct.h"

char *my_strcpy(char *dest, char const *src)
{
    int n = str_l(src);
    for (int i = 0; i <= n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
