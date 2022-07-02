/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** handle_signal
*/

#include "../../include/my.h"

void handle_quit_signal(int status)
{
    my_putstr("\n$> ", 1);
}

void handle_signal(int status)
{
    int id = WTERMSIG(status);

    if (id == 11)
        my_putstr("Segmentation fault", 2);
    if (id == 8)
        my_putstr("Floating exception", 2);
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)", 2);
    my_putstr("\n", 2);
}
