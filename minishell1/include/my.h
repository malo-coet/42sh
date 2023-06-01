/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my.h
*/

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <linux/limits.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

    #define ls "/usr/bin/ls"

void my_putchar(char);
int my_putstr(char const *);
int is_alpha_num(const char *arg);
int is_alpha_num_2(const char *arg);
void skip_spaces_and_tabs(char *, int );
void print_env(my_struct_t *);
int do_set_env(const char *, const char *, my_struct_t *);
void launch(my_struct_t *);
int undo_set_env(const char *, my_struct_t *);
char *my_pwd(my_struct_t *);
char *my_root(my_struct_t *);
int my_strcmp(char const *, char const *);
int my_execve(my_struct_t *, char *);
char *cat_env(const char *, const char *, int);
int env_strlen(char *);
void my_puterror(char);
char *my_strcpy(char *dest, char const *src);
void update_pwd(my_struct_t *get);
void update_oldpwd(my_struct_t *get);
char *change_to_oldpwd(my_struct_t *get);
void da_cd(my_struct_t *);
void affects(char *, my_struct_t *, int);
char *older_pwd(my_struct_t *);
void all_pwd(my_struct_t *);
char *my_strncat(char * , char const *, int);
int check_delimiter(char *, int, char);
int check_delimiter_2(char *, int, char);
char *del_line(char *);
int bin_execve(my_struct_t *);
my_struct_t *back_to_null(my_struct_t *);
char *my_strcat(char *, char const *);
char *catpath(char *, char const *, char **);
int my_put_nbr(int);
int two_strlen(char **);
int word_len(char *, int, int, char);
my_struct_t *value_init(my_struct_t *, char **);
int nb_argv(char **, int);
char **my_str_to_word_array(char *string, char *separator);
char *find_path(char **);
int spec_strlen(char *, char);
int my_putstr_error(char const *);
int my_strncmp(char const *, char const *, int);
int str_l(char const *);
char **space_return_spec(char **, char *);
char **end_path_spec(char **, char *);
char *my_strdup(const char *str);
char *my_strncpy(char *dest, const char *src, int n);
int first_is_alpha(const char *arg);
char *my_old_pwd(my_struct_t *get);
void execute_directory(const char *directory);
void da_cd_2(my_struct_t *buf);
void da_cd_3(my_struct_t *buf);
int is_wrong_architecture(const char *executable);
void cmd_not_found(my_struct_t *get);
void cmd_wrong_architecture(my_struct_t *get);
void cmd_isnot(my_struct_t *get);


#endif /*MY_H_*/
