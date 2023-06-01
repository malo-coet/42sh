/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** value_init.c
*/

#include "my.h"
#include "struct.h"

my_struct_t *value_init(my_struct_t *get, char **env)
{
    my_struct_t *input_get = malloc(sizeof(my_struct_t));
    input_get->env = env;
    input_get->size = 10;
    input_get->str = malloc(sizeof(char) * input_get->size);
    input_get->tab = NULL;
    input_get->chars = 0;
    input_get->ac = 0;
    return input_get;
}

my_struct_t *back_to_null(my_struct_t *get)
{
    get->str = NULL;
    get->tab = NULL;
    get->chars = '\0';
    get->ac = 0;
    return get;
}
