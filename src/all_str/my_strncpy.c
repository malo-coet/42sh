/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strncpy.c
*/

#include "my.h"
#include "struct.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    char *result = dest;

    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }
    while (n > 0) {
        *dest++ = '\0';
        n--;
    }
    return result;
}
