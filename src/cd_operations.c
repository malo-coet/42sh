/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** cd_operations.c
*/

#include "my.h"
#include "struct.h"
#include <dirent.h>
#include <errno.h>
#include <linux/limits.h>

void da_cd_3(my_struct_t *buf)
{
    char **env;
    if (my_strcmp(buf->tab[1], "-n") == 0) {
        chdir(my_root(buf));
        my_putstr("~\n");
        return;
    }
    if (my_strcmp(buf->tab[1], "-p") == 0 || buf->tab[1] == NULL) {
        chdir(my_root(buf));
        my_putstr("~\n");
        return;
    }
    if (my_strcmp(buf->tab[1], "-") == 0 || buf->tab[1] == NULL) {
        chdir(change_to_oldpwd(buf));
        return;
    }
}

void da_cd_2(my_struct_t *buf)
{
    DIR* dir = opendir(buf->tab[1]);
    int i = 0;

    if (dir != NULL) {
        update_oldpwd(buf);
        chdir(buf->tab[1]);
        update_pwd(buf);
        closedir(dir);
        return;
    }
    if (errno != ENOENT) {
        if (errno == ENOTDIR) {
            my_putstr_error(buf->tab[1]);
            my_putstr_error(": Not a directory.\n");
        } else {
            my_putstr_error(buf->tab[1]);
            my_putstr_error(": Permission denied.\n");
        }
    } else if (my_strcmp(buf->tab[1], "-p") != 0 &&
    my_strcmp(buf->tab[1], "-n") != 0 &&
    my_strcmp(buf->tab[1], "-") != 0) {
        my_putstr_error(buf->tab[1]);
        my_putstr_error(": No such file or directory.\n");
    }
}

void da_cd(my_struct_t *buf)
{
    if (buf->tab == NULL || my_strcmp(buf->tab[1], "~") == 0
    || buf->tab[1] == NULL) {
        chdir(my_root(buf));
        return;
    }
    if (my_strcmp(buf->tab[1], "-l") == 0) {
        chdir(my_root(buf));
        my_putstr((my_root(buf)));
        my_putchar('\n');
        return;
    }
    da_cd_2(buf);
    da_cd_3(buf);
}
