/*
** EPITECH PROJECT, 2022
** check_path.c
** File description:
** chek if the path exist
*/

#include "../../include/my.h"

int check_path(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (-1);
    close(fd);
    return (1);
}
