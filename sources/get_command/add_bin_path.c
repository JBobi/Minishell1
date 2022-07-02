/*
** EPITECH PROJECT, 2022
** add_bin_path.c
** File description:
** add the path to the bin
*/

#include "../../include/my.h"

char *add_bin_path(char *command)
{
    int len = my_strlen(command) + 5;
    char *to_return = NULL;

    if ((to_return = malloc(sizeof(char) * len + 1)) == NULL)
        return (NULL);
    to_return = my_strcpy(to_return, "/bin/");
    to_return = my_strcat(to_return, command);
    free(command);
    return (to_return);
}
