/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** print the content of an array of words
*/

#include "../../include/my.h"

int my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i], 1);
        my_putchar('\n');
    }
    return (0);
}
