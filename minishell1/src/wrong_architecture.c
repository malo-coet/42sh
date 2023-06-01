/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** wrong_architecture.c
*/

#include <unistd.h>
#include "my.h"
#include <fcntl.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int check_executable(const char *filename)
{
    if (my_strncmp(filename, "./", 2) != 0)
        return 84;
    struct stat st;
    if (stat(filename, &st) != 0)
        return 84;
    if (!(st.st_mode & S_IXUSR))
        return 84;
    return 0;
}

int is_regular_executable(const char *executable)
{
    struct stat st;
    if (stat(executable, &st) != 0) {
        if (errno == ENOENT) {
            return 8;
        }
    }
    if (!S_ISREG(st.st_mode) || !(st.st_mode & S_IXUSR)) {
        return 84;
    }
    return 0;
}

int is_wrong_architecture(const char *executable)
{
    if (is_regular_executable(executable) == 84) {
        return 84;
    } else if (is_regular_executable(executable) == 8)
        return 8;
    int fd = open(executable, O_RDONLY);
    if (fd == -1) {
        return 0;
    }
    Elf64_Ehdr header;
    close(fd);
    if ((header.e_ident[EI_CLASS] == ELFCLASS64 &&
        header.e_machine != EM_X86_64) ||
        (header.e_ident[EI_CLASS] == ELFCLASS32 &&
        header.e_machine != EM_386)) {
        return 1;
    }
}
