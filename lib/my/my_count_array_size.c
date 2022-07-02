/*
** EPITECH PROJECT, 2022
** my_count_array_size.c
** File description:
** my_count_array_size
*/

#include "../../include/my.h"

int my_count_array_size(char **tab)
{
    int count = 0;

    while (tab[count])
        count += 1;
    return (count);
}
