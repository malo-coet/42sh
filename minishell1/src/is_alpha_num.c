/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** is_alpha_num.c
*/

#include "my.h"

int is_alpha_num(const char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++){
        if (arg[i] < 48) {
            my_putstr_error("setenv: Variable name must contain");
            my_putstr_error(" alphanumeric characters.\n");
            return (84);
        }
    }
    for (int i = 0; arg[i] != '\0'; i++){
        if (arg[i] > 57 && arg[i] < 65) {
            my_putstr_error("setenv: Variable name must contain");
            my_putstr_error(" alphanumeric characters.\n");
            return (84);
        }
    }
    return (0);
}

int is_alpha_num_2(const char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] > 90 && arg[i] < 95) {
            my_putstr_error("setenv: Variable name must contain");
            my_putstr_error(" alphanumeric characters.\n");
            return (84);
        }
        if (arg[i] > 122 || arg[i] == 96) {
            my_putstr_error("setenv: Variable name must contain");
            my_putstr_error(" alphanumeric characters.\n");
            return (84);
        }
    }
    return (0);
}

int first_is_alpha(const char *arg)
{
    if (arg[0] < 65) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    if (arg[0] > 90 && arg[0] < 97) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    if (arg[0] > 122) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    return (0);
}
