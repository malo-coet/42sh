/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** launch_all.c
*/

#include "struct.h"
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int nb_getv(char **input, int ac)
{
    if (input)
        for (int i = 0; input[i] != NULL; i++)
            ac++;
    return ac;
}

void cmd_cmp(my_struct_t *get)
{
    if (get->str != NULL && my_strcmp(get->tab[0], "env") == 0) {
        print_env(get);
        return;
    }
    if (get->str != NULL && my_strcmp(get->tab[0], "cd") == 0) {
        da_cd(get);
        return;
    }
    if (get->str != NULL && my_strcmp(get->tab[0], "setenv") == 0) {
        if (nb_getv(get->tab, get->ac) > 2)
            do_set_env(get->tab[1], get->tab[2], get);
        else
            do_set_env(get->tab[1], NULL, get);
        return;
    }
    if (get->str != NULL && my_strcmp(get->tab[0], "unsetenv") == 0) {
        if (undo_set_env(get->tab[1], get) == 84)
            return;
        undo_set_env(get->tab[1], get);
    }
}

void launch(my_struct_t *get)
{
    char cwd[1024];
    while ((get->chars = getline(&(get->str), &get->size, stdin)) != -1) {
        get->str = del_line(get->str);
        if (my_strcmp(get->str, "exit") == 0)
            exit(0);
        get->tab = my_str_to_word_array(get->str, " \t");
        if (get->tab != NULL) {
            cmd_cmp(get);
            cmd_isnot(get);
        }
        if (isatty(0)) {
            my_putstr("$>");
        }
        get = back_to_null(get);
    }
}
