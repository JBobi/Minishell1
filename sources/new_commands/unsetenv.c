/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unsetenv
*/

#include "../../include/my.h"

void remove_variable(char *name, control_env_l *control)
{
    env_l *node = find_variable(name, control);

    if (node == NULL)
        return;
    if (my_strcmp(node->str, control->last->str) == 0) {
        control->last = node->previous;
        control->last->next = NULL;
        free(node->str);
        free(node);
    } else if (my_strcmp(node->str, control->begin->str) == 0) {
        control->begin = node->next;
        control->begin->previous = NULL;
        free(node->str);
        free(node);
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        free(node->str);
        free(node);
    }
}

void execute_unsetenv(char **command, control_env_l *control)
{
    if (!command[1]) {
        my_putstr("unsetenv: Too few arguments.\n", 2);
        return;
    }
    for (int i = 1; command[i]; i++)
        remove_variable(command[i], control);
}
