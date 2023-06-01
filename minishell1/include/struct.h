/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** struct.h
*/

#include <stdlib.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct my_struct {
    char *str;
    int ac;
    int env_count;
    char *cwd;
    char **tab;
    char **env;
    char *path;
    char *previous_dir;
    size_t size;
    size_t chars;
} my_struct_t;

#endif /*STRUCT_H_*/
