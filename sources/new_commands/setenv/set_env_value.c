/*
** EPITECH PROJECT, 2022
** set_env_value.c
** File description:
** set_env_value
*/

#include "../../../include/my.h"

char *reset_value(char *var)
{
    char *to_return = NULL;
    int len = 0;

    while (var[len] != '=')
        len += 1;
    if ((to_return = malloc(sizeof(char) * (len + 2))) == NULL)
        return (NULL);
    to_return = my_strncpy(to_return, var, len + 1);
    to_return[len + 1] = 0;
    free(var);
    return (to_return);
}

char *give_value(char *var, char *value)
{
    char *to_return = NULL;

    if ((to_return = malloc(sizeof(char) * (my_strlen(var) +
    my_strlen(value) + 1))) == NULL)
        return (NULL);
    to_return = my_strcpy(to_return, var);
    to_return = my_strcat(to_return, value);
    free(var);
    return (to_return);
}

void create_env_var(char *name, control_env_l *control)
{
    env_l *var = NULL;

    if ((var = malloc(sizeof(struct env_s))) == NULL)
        return;
    if ((var->str = malloc(sizeof(char) * (my_strlen(name) + 2))) == NULL)
        return;
    var->str = my_strcpy(var->str, name);
    var->str = my_strcat(var->str, "=");
    var->str[my_strlen(name) + 1] = 0;
    var->next = NULL;
    var->previous = control->last;
    control->last->next = var;
    control->last = var;
}
