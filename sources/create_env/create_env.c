/*
** EPITECH PROJECT, 2022
** create_env.c
** File description:
** put env in a linked list
*/

#include "../../include/my.h"

void free_env_list(control_env_l *control)
{
    env_l *temp = NULL;
    env_l *node = control->begin;

    free(control);
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp->str);
        free(temp);
    }
}

env_l *create_env_node(char *env)
{
    env_l *node = NULL;

    if ((node = malloc(sizeof(struct env_s))) == NULL)
        return (NULL);
    node->str = my_strdup(env);
    node->next = NULL;
    return (node);
}

void create_env_list(char **env, control_env_l *control)
{
    env_l *begin = create_env_node(env[0]);
    env_l *node = begin;

    begin->previous = NULL;
    control->begin = begin;
    for (int i = 1; env[i]; i++) {
        node->next = create_env_node(env[i]);
        node->next->previous = node;
        node = node->next;
    }
    control->last = node;
}

control_env_l *create_control_env(char **env)
{
    control_env_l *control = NULL;

    if ((control = malloc(sizeof(struct control_env_s))) == NULL)
        return (NULL);
    create_env_list(env, control);
    return (control);
}
