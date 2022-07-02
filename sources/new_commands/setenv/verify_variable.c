/*
** EPITECH PROJECT, 2022
** verify_variable.c
** File description:
** verify_variable
*/

#include "../../../include/my.h"

int check_char(char c)
{
    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') &&
    !(c >= '0' && c <= '9') && c != '_')
        return (1);
    return (0);
}

int is_alphanum(char *name)
{
    int status = 0;

    for (int i = 0; name[i]; i++)
        if (check_char(name[i]) == 1)
            return (1);
    return (0);
}

int verify_variable_setenv_name(char *name)
{
    if (is_alphanum(name) == 1) {
        my_putstr("setenv: Variable name must contain ", 2);
        my_putstr("alphanumeric characters.\n", 2);
        return (1);
    }
    if (name[0] >= '0' && name[0] <= '9') {
        my_putstr("setenv: Variable name must begin with a letter.\n", 2);
        return (2);
    }
    return (0);
}
