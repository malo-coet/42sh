/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** del_line.c
*/

#include "struct.h"
#include "my.h"

char *del_line(char *str)
{
    int i = 0;
    int j = 0;
    char *stock = NULL;

    stock = malloc(sizeof(char) * str_l(str));
    if (my_strcmp(str, "\n") == 0)
        return NULL;
    while (str[i] != '\n') {
        stock[i] = str[i];
        i++;
    }
    stock[i] = '\0';
    return stock;
}
