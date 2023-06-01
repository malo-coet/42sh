/*
** EPITECH PROJECT, 2022
** Epitech_2022
** File description:
** my_strtoword.c
*/

#include "my.h"
#include "struct.h"

char **my_str_to_word_array(char *string, char *separator)
{
    if (string == NULL)
        return NULL;
    int num_words;
    char *temp_str = my_strdup(string);
    char *token = strtok(temp_str, separator);
    for (num_words = 0; token != NULL; num_words++)
        token = strtok(NULL, separator);
    char **result = malloc((num_words + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;
    num_words = 0;
    token = strtok(string, separator);
    for (num_words = 0; token != NULL; num_words++) {
        result[num_words] = my_strdup(token);
        token = strtok(NULL, separator);
    }
    result[num_words] = NULL;
    free(temp_str);
    return result;
}
