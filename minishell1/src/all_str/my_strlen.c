/*
** EPITECH PROJECT, 2022
** Epitech_2022
** File description:
** my_strlen.c
*/

#include "my.h"
#include "struct.h"

int str_l(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int spec_strlen(char *str, char delim)
{
    int count = (*str != delim);
    while (*str) {
        count += (*str++ == delim) && (*str != delim);
    }
    return count;
}

int two_strlen(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        i++;
    return i;
}
