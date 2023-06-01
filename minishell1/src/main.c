/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main.c
*/

#include "my.h"
#include "struct.h"
#include <signal.h>

int main(int argc, char **argv, char **env)
{
    my_struct_t *element = value_init(element, env);

    if (argc < 1)
        return (84);
    if (*argv[0] == '\0')
        return (84);
    if (isatty(0))
        my_putstr("$>");
    launch(element);
    return 0;
}
