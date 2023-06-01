/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** cmd_errors.c
*/

#include "struct.h"
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void cmd_wrong_architecture(my_struct_t *get)
{
    int result = is_wrong_architecture(get->tab[0]);
    if (result == 8) {
        my_putstr_error(get->tab[0]);
        my_putstr_error(": Command not found.\n");
    } else if (result == 84) {
        my_putstr_error(get->tab[0]);
        my_putstr_error(": Permission denied.\n");
    } else {
        my_putstr_error(get->tab[0]);
        my_putstr_error(": Exec format error. Wrong Architecture.\n");
    }
}

void cmd_isnot(my_struct_t *get)
{
    if (get->str != NULL && my_execve(get, get->tab[0]) != 0) {
        if (bin_execve(get) != 0 &&
            my_strcmp(get->tab[0], "cd") != 0 &&
            my_strcmp(get->tab[0], "setenv") != 0 &&
            my_strcmp(get->tab[0], "unsetenv") != 0) {
            cmd_wrong_architecture(get);
        }
    }
}
