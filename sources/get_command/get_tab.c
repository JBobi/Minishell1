/*
** EPITECH PROJECT, 2022
** get_tab.c
** File description:
** transform the command in a word array
*/

#include "../../include/my.h"

int is_separator(char c)
{
    if (c != ' ' && c != '\n' && c != '\t')
        return (1);
    return (0);
}

char *copy_words(char *src, int pos)
{
    int size = 0;
    int i = pos;
    int j = 0;
    char *dest = NULL;

    while (is_separator(src[i]) == 1) {
        size += 1;
        i += 1;
    }
    if ((dest = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    while (is_separator(src[pos]) == 1) {
        dest[j] = src[pos];
        j += 1;
        pos += 1;
    }
    dest[j] = 0;
    return (dest);
}

int count_words(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (i == 0 && is_separator(str[i]) == 1)
            count += 1;
        if (i != 0 && is_separator(str[i]) == 1 &&
        is_separator(str[i - 1]) == 0)
            count += 1;
    }
    return (count);
}

char **transform_array(char *command)
{
    char **command_tab = NULL;
    int nb_args = count_words(command);
    int pos = 0;

    if (nb_args == 0)
        return (NULL);
    if ((command_tab = malloc(sizeof(char *) * (nb_args + 1))) == NULL)
        return (NULL);
    command_tab[nb_args] = NULL;
    for (int i = 0; i < nb_args; i++) {
        while (is_separator(command[pos]) == 0)
            pos += 1;
        command_tab[i] = copy_words(command, pos);
        while (is_separator(command[pos]) == 1)
            pos += 1;
    }
    return (command_tab);
}
