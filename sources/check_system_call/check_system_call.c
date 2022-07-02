/*
** EPITECH PROJECT, 2022
** check_system_call.c
** File description:
** check system call
*/

#include "../../include/my.h"

int check_env_command(char **tab, control_env_l *control)
{
    if (my_strcmp(tab[0], "setenv") == 0)
        execute_setenv(tab, control);
    else
        execute_unsetenv(tab, control);
}

int check_system_call(char **tab, control_env_l *control)
{
    if (my_strcmp(tab[0], "cd") == 0) {
        execute_cd(tab, control);
        return (1);
    }
    if (my_strcmp(tab[0], "env") == 0) {
        execute_env(control);
        return (2);
    }
    if (my_strcmp(tab[0], "setenv") == 0 ||
    my_strcmp(tab[0], "unsetenv") == 0) {
        check_env_command(tab, control);
        return (3);
    }
    if (my_strcmp(tab[0], "exit") == 0) {
        execute_exit(tab, control);
        return (4);
    }
    return (0);
}
