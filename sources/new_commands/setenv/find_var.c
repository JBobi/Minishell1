/*
** EPITECH PROJECT, 2022
** find_var.c
** File description:
** find_var
*/

#include "../../../include/my.h"

env_l *find_variable(char *name, control_env_l *control)
{
    int len = my_strlen(name);
    env_l *node = control->last;

    while (node) {
        if (my_strncmp(name, node->str, len) == 0 && node->str[len] == '=')
            return (node);
        node = node->previous;
    }
    return (NULL);
}
