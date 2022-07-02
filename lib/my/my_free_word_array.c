/*
** EPITECH PROJECT, 2022
** my_free_word_array.c
** File description:
** free word array
*/

#include "../../include/my.h"

void my_free_word_array(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
