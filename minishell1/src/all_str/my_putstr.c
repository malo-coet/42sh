/*
** EPITECH PROJECT, 2022
** Epitech_2022
** File description:
** my_putstr.c
*/

#include "my.h"
#include "struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puterror(char c)
{
    write(2, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar (str[i]);
        i++;
    }
    return (0);
}

int my_putstr_error(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_puterror(str[i]);
        i++;
    }
    return (0);
}
