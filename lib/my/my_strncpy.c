/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** copies n characters string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = 0;

    while (src[len] != '\0')
        len += 1;
    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (len < n)
        dest[i] = '\0';
    return (dest);
}
