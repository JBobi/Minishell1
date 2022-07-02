/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main of minishell1 project
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    minishell(ac, av, env);
    return (EXIT_SUCCESS);
}
