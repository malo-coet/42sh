/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** environement_funct.c
*/

#include "my.h"
#include "struct.h"

void print_env(my_struct_t *get)
{
    for (int i = 0; get->env[i] != NULL; i++) {
        my_putstr(get->env[i]);
        my_putchar('\n');
    }
}

void affects(char *str, my_struct_t *get, int i)
{
    char *tmp = NULL;

    while (my_strcmp(get->env[0], str) != 0) {
        tmp = malloc(sizeof(char) * str_l(get->env[i - 1]));
        tmp = get->env[i - 1];
        get->env[i - 1] = str;
        get->env[i] = tmp;
        tmp = NULL;
        i--;
    }
}

int undo_set_env(const char *arg, my_struct_t *get)
{
    int i = 0;

    if (!arg) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return (84);
    }
    while (get->env[i] != NULL) {
        if (my_strncmp(get->env[i], arg, str_l(arg)) == 0) {
            affects(get->env[i], get, i);
            get->env++;
            return (0);
        }
        i++;
    }
    return (0);
}

int set_env_finalprint(const char *arg, my_struct_t *get)
{
    if (arg == NULL) {
        print_env(get);
        return (1);
    }
    if (get->ac > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return 84;
    }
    if (is_alpha_num(arg) == 84 || is_alpha_num_2(arg) == 84
    || first_is_alpha(arg) == 84)
        return 84;
    return (0);
}

int do_set_env(const char *arg, const char *val, my_struct_t *get)
{
    int i = 0;
    int size = str_l(arg);
    int len_env = two_strlen(get->env);
    int r_return = 0;

    if ((r_return = set_env_finalprint(arg, get)) != 0)
        return (r_return);
    while (get->env[i] != NULL) {
        if (my_strncmp(get->env[i], arg, size) == 0) {
            get->env[i] = cat_env(arg, val, (str_l(arg) + str_l(val)));
            return (0);
        }
        i++;
    }
    get->env[i] = cat_env(arg, val, (str_l(arg) + str_l(val)));
    if (i == len_env)
        get->env[i + 1] = NULL;
    return (0);
}
