/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_root.c
*/

#include "my.h"
#include "struct.h"
#include <linux/limits.h>

void replace_pwd(my_struct_t *get, char *home)
{
    int i = 0;
    int j = 0;

    while (my_strncmp(get->env[i], "PWD", 3) != 0)
        i++;
    while (get->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; get->env[i][j] != '\0'; k++) {
        get->env[i][j] = home[k];
        j++;
    }
}

char *my_root(my_struct_t *get)
{
    char *home = malloc(sizeof(char) * PATH_MAX);
    int i = 0;
    int j = 0;

    while (my_strncmp(get->env[i], "HOME", 4) != 0)
        i++;
    while (get->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; get->env[i][j] != '\0'; k++) {
        home[k] = get->env[i][j];
        j++;
        home[k + 1] = '\0';
    }
    replace_pwd(get, home);
    return home;
}

void update_pwd(my_struct_t *get)
{
    int i = 0;
    char *pwd = malloc(sizeof(char) * PATH_MAX);

    getcwd(pwd, PATH_MAX);

    while (my_strncmp(get->env[i], "PWD", 3) != 0)
        i++;

    char *new_pwd = malloc(str_l(pwd) + 5);
    my_strcpy(new_pwd, "PWD=");
    my_strcat(new_pwd, pwd);
    get->env[i] = new_pwd;
}

void update_oldpwd(my_struct_t *get)
{
    int i = 0;
    char *oldpwd = malloc(sizeof(char) * PATH_MAX);

    getcwd(oldpwd, PATH_MAX);

    while (my_strncmp(get->env[i], "OLDPWD", 6) != 0)
        i++;

    char *new_pwd = malloc(str_l(oldpwd) + 5);
    my_strcpy(new_pwd, "OLDPWD=");
    my_strcat(new_pwd, oldpwd);
    get->env[i] = new_pwd;
}

char *change_to_oldpwd(my_struct_t *get)
{
    char *oldpwd = malloc(sizeof(char) * PATH_MAX);
    int i = 0;
    int j = 0;

    while (my_strncmp(get->env[i], "OLDPWD", 6) != 0)
        i++;
    while (get->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; get->env[i][j] != '\0'; k++) {
        oldpwd[k] = get->env[i][j];
        j++;
        oldpwd[k + 1] = '\0';
    }
    return oldpwd;
}
