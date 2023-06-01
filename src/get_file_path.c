/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** get_file_path.c
*/

#include "struct.h"
#include "my.h"

char *path_rm(char *x_path)
{
    int i = 0;
    if (x_path[0] == '\0') {
        return x_path;
    }
    while (x_path[i] != '/') {
        i++;
    }
    x_path += i;
    return x_path;
}

char *find_path(char **env)
{
    int i = 0;
    size_t size_path = 0;
    int x = 1;
    char *path = NULL;

    while (env[i] != NULL && x) {
        i++;
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            size_path = str_l(env[i]);
            x = 0;
        }
    }
    path = malloc(size_path + 1);
    my_strncpy(path, env[i], size_path);
    path[size_path] = '\0';
    path = path_rm(path);
    return path;
}

char *catpath(char *dest , char const *src, char **input)
{
    int i = 0;
    int n = 0;
    int size = str_l(src) + str_l(dest) + str_l(input[0]);
    char *ret = malloc(sizeof(char) * (size + 1));

    while (dest[i] != '\0') {
        ret[i] = dest[i];
        i++;
    }
    ret[i] = '/';
    i++;
    while (src[n] != '\0') {
        ret[i] = src[n];
        n++;
        i++;
    }
    ret[i] = '\0';
    return ret;
}
