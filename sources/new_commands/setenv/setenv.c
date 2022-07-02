/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv
*/

#include "../../../include/my.h"

void setenv_set_value(char **command, control_env_l *control, int command_size)
{
    env_l *node = find_variable(command[1], control);

    if (node == NULL)
        create_env_var(command[1], control);
    else
        node->str = reset_value(node->str);
    if (command_size == 2)
        return;
    if (node == NULL)
        node = control->last;
    node->str = give_value(node->str, command[2]);
}

void execute_setenv(char **command, control_env_l *control)
{
    int command_size = my_count_array_size(command);

    if (command_size > 3) {
        my_putstr("setenv: Too many arguments.\n", 2);
        return;
    }
    if (command_size == 1) {
        execute_env(control);
        return;
    }
    if (verify_variable_setenv_name(command[1]) != 0)
        return;
    setenv_set_value(command, control, command_size);
}
