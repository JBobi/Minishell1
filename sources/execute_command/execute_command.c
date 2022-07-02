/*
** EPITECH PROJECT, 2022
** execute_command.c
** File description:
** execute a command
*/

#include "../../include/my.h"

void execute_function(char **command, control_env_l *control)
{
    int cpid = fork();
    int status = 0;
    char **env_tab = transform_env(control);

    if (cpid == 0) {
        if (execve(command[0], command, env_tab) == -1)
            execute_exit(command, control);
    } else {
        wait(&status);
        if (WIFSIGNALED(status))
            handle_signal(status);
    }
    my_free_word_array(env_tab);
}

void run_command(char **command, control_env_l *control)
{
    if (check_system_call(command, control) == 0) {
        if (check_path(command[0]) == 1) {
            execute_function(command, control);
            return;
        }
        command[0] = add_bin_path(command[0]);
        if (check_path(command[0]) == 1) {
            execute_function(command, control);
            return;
        }
        my_putstr(&command[0][5], 2);
        my_putstr(": Command not found.\n", 2);
    }
}
