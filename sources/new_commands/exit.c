/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** exit
*/

#include "../../include/my.h"

void execute_exit(char **command, control_env_l *control)
{
    if (isatty(0))
        my_putstr("exit\n", 1);
    my_free_word_array(command);
    free_env_list(control);
    exit(EXIT_SUCCESS);
}
