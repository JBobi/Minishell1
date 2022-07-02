/*
** EPITECH PROJECT, 2022
** transform_env.c
** File description:
** transform_env
*/

#include "../../include/my.h"

int list_len(env_l *list)
{
    int len = 0;
    env_l *node = list;

    while (node) {
        len += 1;
        node = node->next;
    }
    return (len);
}

char **transform_env(control_env_l *list)
{
    char **to_return = NULL;
    int len = list_len(list->begin);
    env_l *node = list->begin;

    if ((to_return = malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    to_return[len] = NULL;
    for (int i = 0; i < len; i++) {
        to_return[i] = my_strdup(node->str);
        node = node->next;
    }
    return (to_return);
}
