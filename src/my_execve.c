/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_execve.c
*/

#include "struct.h"
#include "my.h"
#include <signal.h>
#include <wait.h>

int check_err(int status)
{
    if (WIFSIGNALED(status)){
        if (WTERMSIG(status) == SIGFPE) {
            my_putstr_error("Floating exception\n");
            return 84;
        }
        if (WTERMSIG(status) == SIGSEGV) {
            my_putstr_error("Segmentation fault\n");
            return 84;
        }
    }
}

int my_execve(my_struct_t *get, char *path)
{
    int child_status = 0;
    pid_t pid = fork();

    if (pid == 0) {
        if (execve(path, get->tab, get->env) == -1) {
            exit(-1);
        }
        exit(0);
    } else {
        waitpid(pid, &child_status, 0);
        check_err(child_status);
        return WEXITSTATUS(child_status);
    }
}

int bin_execve(my_struct_t *get)
{
    if (my_strcmp(get->tab[0], "cd") == 0) {
        return 84;
    }

    char *path = find_path(get->env);
    char **cleanpath = my_str_to_word_array(path, ":");

    for (int i = 0; cleanpath[i]; i++) {
        char *fullpath = catpath(cleanpath[i], get->tab[0], get->tab);
        int status = my_execve(get, fullpath);
        free(fullpath);
        if (status == 0) {
            return 0;
        }
    }
    return 84;
}
