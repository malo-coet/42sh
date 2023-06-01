/*
** EPITECH PROJECT, 2022
** Epitech_2022
** File description:
** my_strncat.c
*/

#include "my.h"
#include "struct.h"

char *my_strncat(char *dest , char const *src, int n)
{
    int i = 0;
    int j = 0;
    char *output = malloc(sizeof(dest) + sizeof(src));

    while (dest[i] != '\0') {
        output[i] = dest[i];
        i++;
    }
    while (src[j] != '\0' && j < n) {
        output[i] = src[j];
        i++;
        j++;
    }
    output[i] = '\0';
    return output;
}

char *my_strcat(char *dest, char const *src)
{
    int i;
    int last;

    last = 0;
    i = 0;
    while (dest[last] != '\0')
        last++;
    while (src[i] != '\0') {
        dest[last + i] = src[i];
        i++;
    }
    return dest;
}


char *cat_env(const char *name, const char *val, int size)
{
    char *output_val = NULL;
    int i = 0;

    if (!(output_val = malloc(sizeof(char) * (size + 2))))
        return NULL;
    for (i = 0; name[i] != '\0'; i++)
        output_val[i] = name[i];
    output_val[i] = '=';
    i++;
    if (val != NULL) {
        for (int j = 0; val[j] != '\0'; j++) {
            output_val[i] = val[j];
            i++;
        }
    }
    output_val[i] = '\0';
    return output_val;
}
