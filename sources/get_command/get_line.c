/*
** EPITECH PROJECT, 2022
** get_line.c
** File description:
** get a command
*/

#include "../../include/my.h"

int is_space_and_tab(char *str)
{
    for (int i = 0; str[0]; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            return (1);
    }
    return (0);
}

char *get_command(control_env_l *control)
{
    size_t len = 0;
    char *command = NULL;

    if (getline(&command, &len, stdin) == -1) {
        free(command);
        if (isatty(0))
            my_putstr("exit\n", 1);
        free_env_list(control);
        exit(EXIT_SUCCESS);
    }
    return (command);
}

char **get_command_tab(control_env_l *control)
{
    char *command_array = NULL;
    char **command_tab = NULL;

    command_array = get_command(control);
    if (my_strcmp(command_array, "\n") == 0) {
        free(command_array);
        return (NULL);
    }
    if ((command_tab = transform_array(command_array)) == NULL) {
        free(command_array);
        return (NULL);
    }
    free(command_array);
    return (command_tab);
}
