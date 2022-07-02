/*
** EPITECH PROJECT, 2022
** minishell.c
** File description:
** minishell
*/

#include "../../include/my.h"

void minishell(int ac, char **av, char **env)
{
    control_env_l *control = create_control_env(env);
    char **command = NULL;

    signal(SIGINT, &handle_quit_signal);
    while (TRUE) {
        errno = 0;
        if (isatty(0))
            my_putstr("$> ", 1);
        if ((command = get_command_tab(control)) == NULL)
            continue;
        run_command(command, control);
        my_free_word_array(command);
    }
}
