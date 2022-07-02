/*
** EPITECH PROJECT, 2022
** env.c
** File description:
** env
*/

#include "../../include/my.h"

void execute_env(control_env_l *control)
{
    env_l *node = control->begin;

    while (node) {
        my_putstr(node->str, 1);
        my_putchar('\n');
        node = node->next;
    }
}
