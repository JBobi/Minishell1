/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** get_env_value
*/

#include "../../include/my.h"

char *get_env_value(char *var_name, control_env_l *control)
{
    env_l *node = find_variable(var_name, control);
    int start_value = 0;

    if (node == NULL)
        return (NULL);
    while (node->str[start_value] != '=')
        start_value++;
    if (node->str[start_value + 1])
        return (&node->str[start_value + 1]);
    return (NULL);
}
