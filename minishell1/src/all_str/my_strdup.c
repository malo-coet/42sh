/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strdup.c
*/

#include "my.h"
#include "struct.h"

char *my_strdup(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    char *new_str = (char *) malloc((len + 1) * sizeof(char));
    if (new_str == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        new_str[i] = str[i];

    return new_str;
}
